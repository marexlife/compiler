#ifndef COMPILER_CLI_CLI_H_
#define COMPILER_CLI_CLI_H_
#include <expected>
#include <filesystem>
#include <string_view>

namespace compiler::cli {
[[nodiscard]] auto GetUserFilesPath(int argc, const char* const* argv)
    -> std::expected<std::filesystem::path, std::string_view>;
}
#endif  // COMPILER_CLI_CLI_H_