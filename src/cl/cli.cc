#include "cli.h"

#include <expected>
#include <filesystem>
#include <functional>
#include <string_view>
#include <utility>

namespace compiler::cli {
[[nodiscard]] std::expected<std::filesystem::path, std::string_view>
Cli::GetUserFilesPath(const int argc, const char* const* const argv) {
  for (int i = 0; i < argc; ++i) {
    switch (i) {
      case 0:
        continue;
      case 1:
        return std::invoke(
            [&] -> std::expected<std::filesystem::path, std::string_view> {
              const std::filesystem::path path{argv[i]};

              if (path.is_relative()) [[unlikely]] {
                return std::unexpected{
                    "Path is relative.",
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

  return std::unexpected("Path is out of argument range.");
}
}  // namespace compiler::cli
