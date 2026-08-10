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

namespace compiler::app {
void App::run(int argc, char** argv)
{
    auto userFiles = cl::Cli::getUserFilesPath(argc, argv);

    selectAction(
        std::move(userFiles),
        [&](auto&& filepath) { runFileMode(std::move(filepath)); },
        [&]() { runShellMode(); });
}

void App::runFileMode(std::vector<std::filesystem::path>&& filepaths)
{
    for (auto& filepath : filepaths) {
        auto sourceCode = fetch::Fetcher::run(std::move(filepath));

        const auto lexedResult = lexer.run(std::move(sourceCode));

        if (!lexedResult.ok()) [[unlikely]] {
            core::Logger::log(lexedResult.status());

            std::exit(-1);
        }

        std::cin.get();
    }
}

void App::runShellMode()
{
    for (;;) {
        std::cout << "Input a command.\n";

        std::string userCommand;
        std::getline(std::cin, userCommand);
        auto result = lexer.run(std::move(userCommand));

        if (!result.ok()) {
            core::Logger::log(result.status());

            std::cin.get();

            continue;
        }

        lex::LexerPrinter::printLexerResult(*result);
    }
}
} // namespace compiler::app
