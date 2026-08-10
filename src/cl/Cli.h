#ifndef COMPILER_CL_CLI_H
#define COMPILER_CL_CLI_H
#include <filesystem>

#include "absl/status/statusor.h"

namespace compiler::cl {
class Cli final {
  public:
    Cli() = delete;
    Cli(Cli &&) = delete;
    Cli &operator=(Cli &&) = delete;
    Cli(const Cli &) = delete;
    Cli &operator=(const Cli &) = delete;
    ~Cli() = delete;

    [[nodiscard]] static absl::StatusOr<
        std::vector<std::filesystem::path>>
    getUserFilesPath(int argc, char **argv);
};
} // namespace compiler::cl
#endif // COMPILER_CL_CLI_H
