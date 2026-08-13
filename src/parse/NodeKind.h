#ifndef MAREX_PARSE_NODEKIND_H
#define MAREX_PARSE_NODEKIND_H
#include <cstdint>

namespace marex::parse {
enum class [[nodiscard]] NodeKind : std::uint8_t {
    None = 0,
    Var,
    Print,
};
} // namespace marex::parse
#endif // MAREX_PARSE_NODEKIND_H