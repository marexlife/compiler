#include "app.h"

#include <stdexcept>

#include "fetcher.h"
#include "lexer.h"

namespace compiler::app {
void App::Run(int argc, char** argv) {
  SelectAction(argc, argv, RunFileMode, RunShellMode);
}

void App::RunFileMode(std::filesystem::path&& filepath) {
  auto fetched_result = fetch::Fetcher::Run(std::move(filepath));

  auto result = lex::Lexer{}.Run(std::move(fetched_result));

  throw std::runtime_error("not implemented yet");
}

void App::SelectAction(int argc, char** argv,
                       void (&file_action)(std::filesystem::path&&),
                       void (&shell_action)()) {
  if (auto user_filepath = cl::Cli::GetUserFilesPath(argc, argv);
      user_filepath.ok()) [[likely]] {
    file_action(std::move(*user_filepath));
  } else {
    shell_action();
  }
}

void App::RunShellMode() {
  throw std::runtime_error("not implemented yet");
}
}  // namespace compiler::app
