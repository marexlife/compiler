#ifndef COMPILER_CLI_CLI_H_
#define COMPILER_CLI_CLI_H_
#include <filesystem>
#include <optional>

namespace compiler::cli {
[[nodiscard]] std::optional<std::filesystem::path> GetUserFilesPath(
    int argc, const char* const* argv);
}
#endif  // COMPILER_CLI_CLI_H_