#ifndef MAREX_PARSE_CASECHECK_H
#define MAREX_PARSE_CASECHECK_H
#include <string_view>

namespace marex::parse {
[[nodiscard]] bool is_snake_case(std::string_view identifier);
}
#endif  // MAREX_PARSE_CASECHECK_H