#include "App.h"

#include <cstddef>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <string>
#include <string_view>
#include <thread>
#include <utility>
#include <vector>

#include "AppModeKind.h"
#include "Fetcher.h"
#include "Lexer.h"
#include "LexerPrinter.h"
#include "Logger.h"
#include "Parser.h"
#include "TokenStream.h"
#include "absl/status/statusor.h"

namespace marex::app {
void App::run(int argc, char *argv[]) {
    App::selectAction(
        argc, argv,
        [&](int argc, char *argv[]) {
            App::compileFiles(argc, argv);
        },
        [&]() { App::runShellMode(); });
}

void App::compileFiles(int argc, char *argv[]) {
    std::vector<std::jthread> workers;

    workers.reserve(argc - 1);

    for (std::size_t i = 1; std::cmp_less(i, argc); ++i) {
        workers.emplace_back(std::jthread([&]() {
            App::compileFile(std::string_view{argv[i]}, i + 1);
        }));
    }
}

void App::showHelpScreen() {
    static const std::string_view helpScreen = R"(Help screen:
A. --help to get to here
B. 'clear;' to clear the screen in Shell mode
C. list files that should be compiled)";

    std::cout << helpScreen;

    std::exit(-1);
}

void App::compile(std::string &&sourceCode, AppModeKind appModeKind) {
    absl::StatusOr<lex::TokenStream> lexerResult =
        lexer.run(std::move(sourceCode));

    if (!lexerResult.ok()) [[unlikely]] {
        switch (appModeKind) {
        case app::AppModeKind::FileMode:
            core::Logger::logFatalError(lexerResult.status());
            break;
        case app::AppModeKind::ShellMode:
            core::Logger::logError(lexerResult.status());
            break;
        case app::AppModeKind::Undecided: {
            static const std::string_view errorMessage =
                "compiler state is not deicded";

            core::Logger::logFatalError(errorMessage);
        } break;
        default: {
            static const std::string_view errorMessage =
                "compile state is invalid";

            core::Logger::logFatalError(errorMessage);
        } break;
        }
    }

    parse::Parser::run(std::move(*lexerResult));

    lex::LexerPrinter::printLexerResult(*lexerResult);
}

void App::compileFile(std::string_view argument, std::size_t fileId) {
    const bool isDirectory = std::filesystem::is_directory(argument);

    if (!isDirectory) [[unlikely]] {
        core::Logger::logFatalError(
            std::string_view{"is not a directory"});
    }

    std::string sourceCode = fetch::Fetcher::run(argument);

    App::compile(std::move(sourceCode));
}

std::string App::queryUserCommand() {
    std::cout << "Input a command...\n";

    std::string userCommand;
    std::getline(std::cin, userCommand);

    return userCommand;
}

void App::executeUserCommand(std::string &&userCommand) {
    App::compile(std::move(userCommand));
}

void App::runShellIteration() {
    std::string userCommand = queryUserCommand();

    App::executeUserCommand(std::move(userCommand));

    std::cin.get();
}

void App::runShellMode() {
    std::cout << "Shell mode:\n\n";

    for (;;) {
        App::runShellIteration();
    }
}
} // namespace marex::app
