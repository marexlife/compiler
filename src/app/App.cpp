#include "App.h"

#include <cstdlib>
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

namespace compiler::app {
void App::run(int argc, char** argv)
{
    auto userFilePaths = cl::Cli::getUserFilesPath(argc, argv);

    selectAction(
        std::move(userFilePaths),
        [&](auto&& filepath) { compileFiles(std::move(filepath)); },
        [&]() { runShellMode(); });
}

void App::compileFiles(std::vector<std::filesystem::path>&& filepaths)
{
    for (auto& filepath : filepaths) {
        compileFile(filepath);
    }
}

void App::compileFile(std::filesystem::path& filepath)
{
    auto sourceCode = fetch::Fetcher::run(std::move(filepath));

    const auto lexedResult = lexer.run(std::move(sourceCode));

    if (!lexedResult.ok()) [[unlikely]] {
        core::Logger::logFatal(lexedResult.status());
    }

    std::cin.get();
}

std::string App::queryUserCommand()
{
    std::cout << "Input a command.\n";

    std::string userCommand;
    std::getline(std::cin, userCommand);

    return userCommand;
}

void App::executeUserCommand(std::string&& userCommand)
{
    auto lexerResult = lexer.run(std::move(userCommand));

    if (!lexerResult.ok()) {
        core::Logger::logError(lexerResult.status());

        std::cin.get();

        return;
    }

    lex::LexerPrinter::printLexerResult(*lexerResult);

    parse::Parser::run(std::move(*lexerResult));
}

void App::runShellMode()
{
    for (;;) {
        std::string userCommand = queryUserCommand();

        executeUserCommand(std::move(userCommand));
    }
}
} // namespace compiler::app
