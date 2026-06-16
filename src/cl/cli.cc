#include "cli.h"

#include <expected>
#include <filesystem>
#include <functional>
#include <string_view>
#include <utility>

#include "absl/status/status.h"

namespace compiler::cl {
[[nodiscard]] absl::StatusOr<std::filesystem::path> Cli::GetUserFilesPath(
    const int argc, const char* const* const argv) {
  for (int i = 0; i < argc; ++i) {
    switch (i) {
      case 0:
        continue;
      case 1:
        return std::invoke([&] -> absl::StatusOr<std::filesystem::path> {
          const std::filesystem::path path{argv[i]};

          if (path.is_relative()) [[unlikely]] {
            return absl::InvalidArgumentError("Path is relative.");
          }

          return absl::StatusOr<std::filesystem::path>{path};
        });
      default:
        std::unreachable();
    }
  }

  return absl::OutOfRangeError("Path is out of range");
}
}  // namespace compiler::cl
