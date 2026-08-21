#include "Fetcher.h"

#include <fstream>
#include <string>
#include <string_view>

namespace marex::fetch {
[[nodiscard]] std::string Fetcher::run(std::string_view filepath) {
    std::ifstream input_filestream{filepath.data()};
    std::string result;

    result.reserve(result_reserve_amount);

    while (!input_filestream.eof()) {
        result += static_cast<char>(input_filestream.get());
    }

    return result;
}
} // namespace marex::fetch
