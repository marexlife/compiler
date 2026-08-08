#include "app.h"

#include <format>
#include <iostream>
#include <string>
#include <utility>

#include "fetcher.h"
#include "lex_printer.h"
#include "lexer.h"
#include "spdlog/spdlog.h"

namespace compiler::app {
void App::run(int argc, char** argv) 
{
  selectAction(
      argc, argv,
      [&](auto&& filepath) { runFileMode(std::move(filepath)); },
      [&]() { runShellMode(); }
  );
}

void App::runFileMode(std::filesystem::path&& filepath) 
{
    auto fetchedResult = fetch::Fetcher::run(std::move(filepath));

    auto lexedResult = lexer.run(std::move(fetchedResult));

    std::cin.get();
}

void App::runShellMode()
{
    for (;;) {
        std::cout << "Input a command.\n";

        std::string userCommand;
        std::getline(std::cin, userCommand);
        auto result = lexer.run(std::move(userCommand));

        if (!result.ok()) {
            spdlog::error(std::format("Error: {}", result.status().message()));

            std::cin.get();

            continue;
        }

        lex::LexPrinter::PrintLexerResult(*result);
    }
}
}  // namespace compiler::app
