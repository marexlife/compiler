#include "app.h"

#include <exception>
#include <iostream>
#include <string>

#include "fetcher.h"
#include "lexer.h"

namespace compiler::app {
void App::Run(int argc, char** argv) {
  SelectAction(
      argc, argv,
      [this](auto&& filepath) { RunFileMode(std::move(filepath)); },
      [this]() { RunShellMode(); });
}

void App::RunFileMode(std::filesystem::path&& filepath) {
  auto fetched_result = fetch::Fetcher::Run(std::move(filepath));

  auto result = lexer_.Run(std::move(fetched_result));

  std::cout << "Not implemented yet.";
  std::terminate();
}

void App::RunShellMode() {
  for (;;) {
    std::string command;
    std::getline(std::cin, command);
    auto result = lexer_.Run(std::move(command));

    if (!result.ok()) {
      std::cout << "Error: " << result.status().message() << '\n';
      std::terminate();
    }

    for (auto& e : *result) {
      for (auto& e2 : e) {
        std::cout << e2.lexeme() << ", ";
      }
    }
  }
}
}  // namespace compiler::app
