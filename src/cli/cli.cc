#include "cli.h"

#include <filesystem>
#include <functional>
#include <optional>
#include <utility>

namespace compiler::cli {
[[nodiscard]] std::optional<std::filesystem::path> GetUserFilesPath(
    const int argc, const char* const* const argv) {
  for (int i = 0; i < argc; ++i) {
    switch (i) {
      case 0:
        continue;
      case 1:
        return std::invoke([&] -> std::optional<std::filesystem::path> {
          std::filesystem::path path{argv[i]};

          if (path.is_relative()) [[unlikely]] {
            return std::nullopt;
          }

          return path;
        });
      default:
        std::unreachable();
    }
  }

  return std::nullopt;
}
}  // namespace compiler::cli