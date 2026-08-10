#include "App.h"

#include <cstddef>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include "Cli.h"
#include "Fetcher.h"
#include "Lexer.h"
#include "LexerPrinter.h"
#include "Logger.h"
#include "Parser.h"
#include "TokenStream.h"
#include "absl/status/statusor.h"

namespace compiler::app {
void App::run(int argc, char *argv[]) {
    App::selectAction(
        argc, argv,
        [&](int argc, char *argv[]) {
            App::compileFiles(argc, argv);
        },
        [&]() { App::runShellMode(); });
}

void App::compileFiles(int argc, char *argv[]) {
    for (std::size_t i = 0; std::cmp_less(i, argc); ++i) {
        App::compileFile(std::string_view{argv[i]}, i + 1);
    }
}

void App::compileFile(std::string_view argument, std::size_t fileId) {
    bool isDirectory = std::filesystem::is_directory(argument);

    if (!isDirectory) [[unlikely]] {
        core::Logger::logFatal(
            std::string_view{"is not a directory"});
    }

    std::string sourceCode = fetch::Fetcher::run(std::move(argument));

    const absl::StatusOr<lex::TokenStream> lexedResult =
        lexer.run(std::move(sourceCode));

    if (!lexedResult.ok()) [[unlikely]] {
        core::Logger::logFatal(lexedResult.status());
    }

    std::cin.get();
}

std::string App::queryUserCommand() {
    std::cout << "Input a command.\n";

    std::string userCommand;
    std::getline(std::cin, userCommand);

    return userCommand;
}

void App::executeUserCommand(std::string &&userCommand) {
    absl::StatusOr<lex::TokenStream> lexerResult =
        lexer.run(std::move(userCommand));

    if (!lexerResult.ok()) {
        core::Logger::logError(lexerResult.status());

        std::cin.get();

        return;
    }

    lex::LexerPrinter::printLexerResult(*lexerResult);

    parse::Parser::run(std::move(*lexerResult));
}

void App::runShellIteration() {
    std::string userCommand = queryUserCommand();

    executeUserCommand(std::move(userCommand));
}

void App::runShellMode() {
    for (;;) {
        runShellIteration();
    }
}
} // namespace compiler::app
