#include "Cli.h"

#include <cstddef>
#include <filesystem>
#include <utility>

#include "absl/status/status.h"

namespace compiler::cl {
[[nodiscard]] absl::StatusOr<std::filesystem::path>
Cli::getUserFilesPath(const int argc, const char* const* const argv)
{
    for (std::size_t i = 0; std::cmp_less(i, argc); ++i) {
        switch (i) {
        case 0:
            [[fallthrough]];
        case 1:
            continue;
        default:
            if (argv[i] == nullptr) {
                return absl::InvalidArgumentError(
                    "Argument is null.");
            }

            const std::filesystem::path path = argv[i];

            if (path.is_relative()) [[unlikely]] {
                return absl::InvalidArgumentError(
                    "Path is relative.");
            }

            return path;
        }
    }

    return absl::OutOfRangeError("Path is out of range");
}
} // namespace compiler::cl
