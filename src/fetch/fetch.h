#ifndef COMPILER_FETCH_FETCH_H_
#define COMPILER_FETCH_FETCH_H_
#include <filesystem>
#include <string>

namespace compiler::fetch {
[[nodiscard]] std::basic_string<int> Fetch(
    const std::filesystem::path& file_path);
}
#endif  // COMPILER_FETCH_FETCH_H_