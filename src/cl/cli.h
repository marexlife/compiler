#ifndef COMPILER_CLI_CLI_H_
#define COMPILER_CLI_CLI_H_
#include <expected>
#include <filesystem>
#include <string_view>

namespace compiler::cli {
class Cli final {
 public:
  Cli() = default;
  Cli(Cli&&) = delete;
  Cli& operator=(Cli&&) = delete;
  Cli(const Cli&) = delete;
  Cli& operator=(const Cli&) = delete;
  ~Cli() = default;

  [[nodiscard]] static std::expected<std::filesystem::path, std::string_view>
  GetUserFilesPath(int argc, const char* const* argv);
};
}  // namespace compiler::cli
#endif  // COMPILER_CLI_CLI_H_