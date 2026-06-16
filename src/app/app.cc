#include "app.h"

#include "cli.h"

namespace compiler::app {
auto App::Run(const int argc, const char* const* const argv) noexcept -> void {
  const auto user_file_path = compiler::cli::GetUserFilesPath(argc, argv);
}
}  // namespace compiler::app