#ifndef COMPILER_CLI_CLI_H_
#define COMPILER_CLI_CLI_H_
#include <filesystem>

namespace compiler::cli {
[[nodiscard]] std::filesystem::path GetUserFilesPath();
}
#endif  // COMPILER_CLI_CLI_H_