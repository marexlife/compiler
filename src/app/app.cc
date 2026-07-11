#include "app.h"

#include <cstdint>
#include <stdexcept>
#include <string_view>

#include "fetcher.h"
#include "lexer.h"

namespace compiler::app {
void App::Run(int argc, char** argv) {
  SelectAction(argc, argv, RunFileMode, RunShellMode);
}

void App::RunFileMode(std::filesystem::path filepath) {
  auto fetched_result = fetch::Fetcher::Run(filepath);

  auto result = lex::Lexer{}.Run(std::move(fetched_result));

  throw std::runtime_error("not implemented yet");
}

void App::RunShellMode() { throw std::runtime_error("not implemented yet"); }
}  // namespace compiler::app
