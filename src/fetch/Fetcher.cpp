#include "Fetcher.h"

#include <fstream>
#include <string>
#include <string_view>

namespace marex::fetch {
[[nodiscard]] std::string Fetcher::run(
    std::string_view filepath) {
    std::ifstream stream{filepath.data()};
    std::string result;

    result.reserve(result_reserve_amount);

    while (!stream.eof()) {
        result += static_cast<char>(stream.get());
    }

    return result;
}
}  // namespace marex::fetch
