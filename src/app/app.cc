#include "app.h"

#include <iostream>
#include <string>

#include "fetcher.h"
#include "lexer.h"

namespace compiler::app {
void App::Run(int argc, char** argv) {
  SelectAction(
      argc, argv,
      [&](auto&& filepath) { RunFileMode(std::move(filepath)); },
      [&]() { RunShellMode(); });
}

void App::RunFileMode(std::filesystem::path&& filepath) {
  auto fetched_result = fetch::Fetcher::Run(std::move(filepath));

  auto result = lexer_.Run(std::move(fetched_result));

  std::cout << "Not implemented yet.";
  std::cin.get();
  return;
}

void App::RunShellMode() {
  for (;;) {
    std::cout << "Input a command.\n";

    std::string command;
    std::getline(std::cin, command);
    auto result = lexer_.Run(std::move(command));

    if (!result.ok()) {
      std::cout << "Error: " << result.status().message() << '\n';
      std::cin.get();
      continue;
    }

    for (auto& e : *result) {
      std::cout << "Statement: ";

      for (auto& e2 : e) {
        std::cout << "Token: " << e2.lexeme() << ' ';
      }
    }
    std::cout << "\n";
  }
}
}  // namespace compiler::app
