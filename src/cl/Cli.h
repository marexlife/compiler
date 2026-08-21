#ifndef MAREX_CL_CLI_H
#define MAREX_CL_CLI_H
#include <filesystem>

#include "absl/status/statusor.h"

namespace marex::cl {
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
    get_user_files_path(int argc, char **argv);
};
} // namespace marex::cl
#endif // MAREX_CL_CLI_H
