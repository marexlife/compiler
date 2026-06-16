#include "app.h"

#include "cli.h"

namespace compiler::app {
auto app::run(const int argc, const char* const* const argv) noexcept -> void {
  const auto user_file_path = compiler::cli::get_user_files_path(argc, argv);
}
}  // namespace compiler::app