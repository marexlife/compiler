#include "app.h"

#include <filesystem>

#include "cli.h"

namespace compiler::app {
void App::Run(int argc, const char* const* const argv) {
  std::filesystem::path user_file_path =
      compiler::cli::GetUserFilesPath(argc, argv);
}
}  // namespace compiler::app