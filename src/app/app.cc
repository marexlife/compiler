#include "app.h"

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
  const auto file_system_path = std::invoke([&] {
    if (const auto user_file_path = Cli::GetUserFilesPath(argc, argv))
        [[likely]] {
      return *user_file_path;
    } else {
      std::println("{}", user_file_path.error());
      std::terminate();
    }
  });

  const auto fetched_result = fetch::Fetcher::Run(file_system_path);

  const auto result = lex::Lexer::Run(fetched_result);
}
}  // namespace compiler::app