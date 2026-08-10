#include "App.h"

#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <string>
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
void App::run(int argc, char **argv) {
    absl::StatusOr<std::vector<std::filesystem::path>> userFilePaths =
        cl::Cli::getUserFilesPath(argc, argv);

    App::selectAction(
        std::move(userFilePaths),
        [&](std::vector<std::filesystem::path> &&filepaths) {
            App::compileFiles(std::move(filepaths));
        },
        [&]() { App::runShellMode(); });
}

void App::compileFiles(
    std::vector<std::filesystem::path> &&filepaths) {
    for (auto &filepath : filepaths) {
        App::compileFile(filepath);
    }
}

void App::compileFile(std::filesystem::path &filepath) {
    std::string sourceCode = fetch::Fetcher::run(std::move(filepath));

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
