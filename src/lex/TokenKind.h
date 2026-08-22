#ifndef MAREX_LEX_TOKENKIND_H
#define MAREX_LEX_TOKENKIND_H
#include <cstdint>

namespace marex::lex {
enum class [[nodiscard]] TokenKind : std::uint8_t {
    None = 0,
    Identifier,
    Set,
    Print,
    Var,
    Number,
    Literal,
};
}
#endif // MAREX_LEX_TOKENKIND_H
