#include "app.h"

#include <iostream>
#include <string>

#include "fetcher.h"
#include "lexer.h"

namespace compiler::app {
void App::Run(int argc, char** argv) {
  SelectAction(
      argc, argv, [this](auto filepath) { RunFileMode(filepath); },
      [this]() { RunShellMode(); });
}

void App::RunFileMode(std::filesystem::path&& filepath) {
  auto fetched_result = fetch::Fetcher::Run(std::move(filepath));

  const auto result = lexer_.Run(std::move(fetched_result));

  std::cout << "Not implemented yet";
  std::terminate();
}

void App::RunShellMode() {
  for (;;) {
    std::string command;
    std::getline(std::cin, command);
    const auto result = lexer_.Run(std::move(command));
  }
}
}  // namespace compiler::app
