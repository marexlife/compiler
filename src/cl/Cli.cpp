#include "Cli.h"

#include <cstddef>
#include <filesystem>
#include <stdexcept>
#include <utility>
#include <vector>

namespace marex::cl {
[[nodiscard]] std::vector<std::filesystem::path>
Cli::get_user_files_path(int argc, char** argv) {
    std::vector<std::filesystem::path> results;

    for (std::size_t i = 0; std::cmp_less(i, argc);
         ++i) {
        switch (i) {
            case 0:
                [[fallthrough]];
            case 1:
                continue;
            default:
                if (argv[i] == nullptr) {
                    throw std::invalid_argument(
                        "Argument is null.");
                }

                const std::filesystem::path path =
                    argv[i];

                if (path.is_relative()) [[unlikely]] {
                    throw std::invalid_argument(
                        "path is relative.");
                }

                results.emplace_back(std::move(path));
        }
    }

    return results;
}
}  // namespace marex::cl
