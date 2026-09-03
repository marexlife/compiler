#ifndef MAREX_PARSE_CASECHECK_H
#define MAREX_PARSE_CASECHECK_H
#include <string_view>

namespace marex::parse {
[[nodiscard]] bool is_snake_case(
    std::string_view identifier);

[[nodiscard]] bool is_pascal_case(
    std::string_view identifier);
}  // namespace marex::parse
#endif  // MAREX_PARSE_CASECHECK_H