#ifndef MAREX_PARSE_TYPEKIND_H
#define MAREX_PARSE_TYPEKIND_H
#include <cstdint>

namespace marex::parse {
enum class [[nodiscard]] TypeKind : std::uint8_t {
    None = 0,
    EmptyType,
    IntType,
    BoolType,
    FloatType,
};
}
#endif  // MAREX_PARSE_TYPEKIND_H