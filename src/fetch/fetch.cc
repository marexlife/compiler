#include "fetch.h"

#include <cstddef>
#include <filesystem>
#include <fstream>
#include <string>

namespace compiler::fetch {
[[nodiscard]] std::basic_string<int> Fetch(
    const std::filesystem::path& file_path) {
  std::ifstream input_file_stream{file_path};

  std::basic_string<int> result{};
  {
    static const std::size_t kResultReserveAmount{100};

    result.reserve(kResultReserveAmount);
  }

  while (!input_file_stream.eof()) {
    result += input_file_stream.get();
  }

  return result;
}
}  // namespace compiler::fetch