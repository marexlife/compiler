#include "fetcher.h"

#include <cstddef>
#include <filesystem>
#include <fstream>
#include <string>

namespace compiler::fetch {
[[nodiscard]] std::basic_string<int> Fetcher::Fetch(
    const std::filesystem::path& filepath) {
  std::ifstream input_filestream{filepath};

  std::basic_string<int> result{};
  {
    static const std::size_t kResultReserveAmount{100};

    result.reserve(kResultReserveAmount);
  }

  while (!input_filestream.eof()) {
    result += input_filestream.get();
  }

  return result;
}
}  // namespace compiler::fetch