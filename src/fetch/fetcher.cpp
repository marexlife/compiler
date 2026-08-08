#include "fetcher.h"

#include <cstddef>
#include <filesystem>
#include <fstream>
#include <string>

namespace compiler::fetch {
[[nodiscard]] std::string Fetcher::run(std::filesystem::path&& filepath) 
{
    std::ifstream inputFilestream{filepath};
    std::string result;
    
    result.reserve(resultReserveAmount);

    while (!inputFilestream.eof()) {
        result += static_cast<char>(inputFilestream.get());
    }

    return result;
}
}  // namespace compiler::fetch