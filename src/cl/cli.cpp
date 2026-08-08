#include "cli.h"

#include <exception>
#include <filesystem>
#include <utility>

#include "absl/status/status.h"

namespace compiler::cl {
[[nodiscard]] absl::StatusOr<std::filesystem::path>
Cli::getUserFilesPath(const int argc, const char* const* const argv) 
{
    for (int i = 0; i < argc; ++i) {
        switch (i) {
            case 0:
            [[fallthrough]];
            case 1:
            continue;
            case 2: {
                const std::filesystem::path path = argv[i];

                if (path.is_relative()) [[unlikely]] {
                    return absl::InvalidArgumentError("Path is relative.");
                }

                return path;
            }
            default:
                std::terminate();
        }
    }

    return absl::OutOfRangeError("Path is out of range");
}
}  // namespace compiler::cl
