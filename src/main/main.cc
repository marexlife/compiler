#include "cl.h"

using compiler::cl::Cli;

int main(const int argc, const char* const* const argv) {
  const auto user_file_path = Cli::GetUserFilesPath(argc, argv);
}
