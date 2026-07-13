#ifndef COMPILER_APP_APP_H_
#define COMPILER_APP_APP_H_
#include <filesystem>
#include <type_traits>

#include "cli.h"

namespace compiler::app {
/// The main Application Logic
class App final {
 public:
  App() = delete;
  App(App&&) = delete;
  App& operator=(App&&) = delete;
  App(const App&) = delete;
  App& operator=(const App&) = delete;
  ~App() = delete;

  static void Run(int argc, char** argv);

  template <typename FileAction, typename ShellAction>
    requires std::is_invocable_v<FileAction, std::filesystem::path> &&
             std::is_invocable_v<ShellAction>
  static void SelectAction(int argc, char** argv,
                           FileAction file_action,
                           ShellAction shell_action) {
    if (const auto user_filepath =
            cl::Cli::GetUserFilesPath(argc, argv);
        user_filepath.ok()) [[likely]] {
      file_action(std::move(*user_filepath));
    } else {
      shell_action();
    }
  }

  static void RunFileMode(std::filesystem::path&& filepath);
  static void RunShellMode();
};
}  // namespace compiler::app
#endif  // COMPILER_APP_APP_H_
