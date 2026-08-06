#include "app.h"

#include <format>
#include <iostream>
#include <string>
#include <utility>

#include "fetcher.h"
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
  auto fetched_result = fetch::Fetcher::Run(std::move(filepath));

  auto result = lexer_.Run(std::move(fetched_result));

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
      spdlog::error(
          std::format("Error: {}", result.status().message()));
      std::cin.get();

      continue;
    }

    for (auto& e : *result) {
      spdlog::info("Statement: ");

      for (auto& e2 : e) {
        spdlog::info(std::format("Token: {}", e2.lexeme()));
      }
    }

    std::cout << "\n";
  }
}
}  // namespace compiler::app
