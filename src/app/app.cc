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
void App::Run(int argc, char** argv) {
  SelectAction(
      argc, argv,
      [&](auto&& filepath) { RunFileMode(std::move(filepath)); },
      [&]() { RunShellMode(); });
}

void App::RunFileMode(std::filesystem::path&& filepath) {
  auto fetchedResult = fetch::Fetcher::Run(std::move(filepath));

  auto lexedResult = m_lexer.Run(std::move(fetchedResult));

  std::cin.get();
  return;
}

void App::RunShellMode() {
  for (;;) {
    std::cout << "Input a command.\n";

    std::string userCommand;
    std::getline(std::cin, userCommand);
    auto result = m_lexer.Run(std::move(userCommand));

    if (!result.ok()) {
      spdlog::error(
          std::format("Error: {}", result.status().message()));

      std::cin.get();

      continue;
    }

    lex::LexPrinter::PrintLexerResult(*result);
  }
}
}  // namespace compiler::app
