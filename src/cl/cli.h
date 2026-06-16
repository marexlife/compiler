#ifndef COMPILER_CL_CLI_H_
#define COMPILER_CL_CLI_H_
#include <expected>
#include <filesystem>
#include <string_view>

#include "absl/status/statusor.h"

namespace compiler::cl {
class Cli final {
 public:
  Cli() = default;
  Cli(Cli&&) = delete;
  Cli& operator=(Cli&&) = delete;
  Cli(const Cli&) = delete;
  Cli& operator=(const Cli&) = delete;
  ~Cli() = default;

  [[nodiscard]] static absl::StatusOr<std::filesystem::path> GetUserFilesPath(
      int argc, const char* const* argv);
};
}  // namespace compiler::cl
#endif  // COMPILER_CL_CLI_H_