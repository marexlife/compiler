#include "app.h"

#include <cstdlib>
#include <exception>
#include <filesystem>
#include <functional>
#include <print>

#include "cli.h"
#include "fetcher.h"
#include "lexer.h"

using compiler::cl::Cli;

namespace compiler::app {
void App::Run(const int argc, const char* const* const argv) {
  if (const auto user_file_path = Cli::GetUserFilesPath(argc, argv);
      user_file_path.ok()) [[likely]] {
    auto fetched_result = fetch::Fetcher::Run(*user_file_path);

    auto result = lex::Lexer{}.Run(std::move(fetched_result));

    
  } else {
    std::println("{}", user_file_path.status().message());
    exit(0);
  }
}
}  // namespace compiler::app
