#ifndef MAREX_PARSE_CASECHECKKIND_H
#define MAREX_PARSE_CASECHECKKIND_H
#include <cstdint>

namespace marex::parse {
enum struct [[nodiscard]] ExpectedCaseKind : std::
    uint8_t {
        None = 0,
        SnakeCase,
        PascalCase,
    };
}
#endif  // MAREX_PARSE_CASECHECKKIND_H