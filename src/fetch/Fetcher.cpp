#include "Fetcher.h"

#include <fstream>
#include <string>
#include <string_view>

namespace marex::fetch {
[[nodiscard]] std::string Fetcher::run(std::string_view filepath) {
    std::ifstream inputFilestream{filepath.data()};
    std::string result;

    result.reserve(resultReserveAmount);

    while (!inputFilestream.eof()) {
        result += static_cast<char>(inputFilestream.get());
    }

    return result;
}
} // namespace marex::fetch
