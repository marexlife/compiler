#include "CaseCheck.h"

#include <algorithm>
#include <cctype>

namespace marex {
namespace parse {
[[nodiscard]] bool is_lower(char input);
[[nodiscard]] bool is_upper(char input);
[[nodiscard]] bool is_underscore(char input);
}  // namespace parse

[[nodiscard]] bool parse::is_snake_case(
    std::string_view identifier) {
    return std::ranges::all_of(
        identifier, [](char input) {
            return parse::is_lower(input) ||
                   parse::is_underscore(input);
        });
}

[[nodiscard]] bool parse::is_pascal_case(
    std::string_view identifier) {
    
    return std::ranges::all_of(
        identifier, [](char input) {
            return parse::is_upper(input) &&
                   !parse::is_underscore(input);
        });
}

namespace parse {
[[nodiscard]] bool is_lower(char input) {
    return !is_upper(input);
}

[[nodiscard]] bool is_upper(char input) {
    return static_cast<bool>(std::isupper(
        static_cast<unsigned char>(input)));
}

[[nodiscard]] bool is_underscore(char input) {
    static const char underscore = '_';
    return input == underscore;
}
}  // namespace parse
}  // namespace marex