#include "fetcher.h"

#include <cstddef>
#include <filesystem>
#include <fstream>
#include <string>

namespace compiler::fetch {
[[nodiscard]] std::string Fetcher::Run(const std::filesystem::path& filepath) {
  std::ifstream input_filestream{filepath};

  std::string result{};
  {
    static const std::size_t kResultReserveAmount{100};

    result.reserve(kResultReserveAmount);
  }

  while (!input_filestream.eof()) {
    result += static_cast<char>(input_filestream.get());
  }

  return result;
}
}  // namespace compiler::fetch