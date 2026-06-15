#include "app.h"

#include "cli.h"

namespace A {}

namespace compiler::app {
void App::Run(const int argc, const char* const* const argv) {
  const auto user_file_path = compiler::cli::GetUserFilesPath(argc, argv);
}
}  // namespace compiler::app