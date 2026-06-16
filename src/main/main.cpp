#include "cli.h"

auto main(const int argc, const char* const* const argv) -> int {
  const auto user_file_path = compiler::cli::get_user_files_path(argc, argv);
}
