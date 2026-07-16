#ifndef COMPILER_APP_APP_H_
#define COMPILER_APP_APP_H_
#include <algorithm>
#include <filesystem>
#include <type_traits>

#include "absl/functional/function_ref.h"
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

  static void SelectAction(
      int argc, char** argv,
      void (&file_action)(std::filesystem::path&&),
      void (&shell_action)());

  static void RunFileMode(std::filesystem::path&& filepath);
  static void RunShellMode();
};
}  // namespace compiler::app
#endif  // COMPILER_APP_APP_H_
