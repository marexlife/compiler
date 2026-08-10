#include "App.h"

#include <cstdlib>
#include <format>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "Fetcher.h"
#include "Lexer.h"
#include "LexerPrinter.h"
#include "spdlog/spdlog.h"

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
        auto fetchedResult = fetch::Fetcher::run(std::move(filepath));

        auto lexedResult = lexer.run(std::move(fetchedResult));

        if (!lexedResult.ok()) [[unlikely]] {
            std::cout << lexedResult.status().message() << '\n';

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
            spdlog::error(
                std::format("Error: {}", result.status().message()));

            std::cin.get();

            continue;
        }

        lex::LexerPrinter::printLexerResult(*result);
    }
}
} // namespace compiler::app
