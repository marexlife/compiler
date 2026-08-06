#ifndef COMPILER_APP_APP_H_
#define COMPILER_APP_APP_H_
#include <algorithm>
#include <filesystem>
#include <type_traits>

#include "absl/functional/function_ref.h"
#include "cli.h"
#include "lexer.h"

namespace compiler::app {
/// The main Application Logic
class App final {
 public:
  App() = default;

  void Run(int argc, char** argv);

  template <typename FileAction, typename ShellAction>
  static void SelectAction(int argc, char** argv,
                           FileAction file_action,
                           ShellAction shell_action) {
    if (auto user_filepath = cl::Cli::GetUserFilesPath(argc, argv);
        user_filepath.ok()) [[likely]] {
      file_action(std::move(*user_filepath));
    } else {
      shell_action();
    }
  }

  void RunFileMode(std::filesystem::path&& filepath);
  void RunShellMode();

 private:
  lex::Lexer lexer_{};
};
}  // namespace compiler::app
#endif  // COMPILER_APP_APP_H_
