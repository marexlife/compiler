#include "CaseCheck.h"

#include <algorithm>
#include <cctype>

namespace marex {
namespace parse {
[[nodiscard]] bool is_lower(char input);
}

[[nodiscard]] bool parse::is_snake_case(
    std::string_view identifier) {
    return std::ranges::all_of(identifier,
                               parse::is_lower);
}

namespace parse {
[[nodiscard]] bool is_lower(char input) {
    return !static_cast<bool>(std::isupper(
        static_cast<unsigned char>(input)));
}
}  // namespace parse
}  // namespace marex