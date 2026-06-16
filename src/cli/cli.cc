#include "cli.h"

#include <expected>
#include <filesystem>
#include <functional>
#include <string_view>
#include <utility>

namespace compiler::cli {
[[nodiscard]] auto GetUserFilesPath(const int argc,
                                    const char* const* const argv) noexcept
    -> std::expected<std::filesystem::path, std::string_view> {
  static const std::string_view kPathIsRelativeErrorMessage =
      "Path is relative.";

  static const std::string_view kPathIsOutOfArgumentRange =
      "Path is out of argument range.";

  for (int i = 0; i < argc; ++i) {
    switch (i) {
      case 0:
        continue;
      case 1:
        return std::invoke(
            [&] -> std::expected<std::filesystem::path, std::string_view> {
              std::filesystem::path path{argv[i]};

              if (path.is_relative()) [[unlikely]] {
                return std::unexpected{
                    kPathIsRelativeErrorMessage,
                };
              }

              return std::expected<std::filesystem::path, std::string_view>{
                  path,
              };
            });
      default:
        std::unreachable();
    }
  }

  return std::unexpected(kPathIsOutOfArgumentRange);
}
}  // namespace compiler::cli