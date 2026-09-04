#ifndef MAREX_PARSE_TYPEKIND_H
#define MAREX_PARSE_TYPEKIND_H
#include <cstdint>
#include <string_view>

namespace marex::parse {
enum class [[nodiscard]] TypeKind : std::uint8_t {
    None = 0,
    EmptyType,
    IntType,
    BoolType,
    FloatType,
};

[[nodiscard]] std::string_view operator*(TypeKind token_kind);
}
#endif  // MAREX_PARSE_TYPEKIND_H