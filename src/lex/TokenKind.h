#ifndef MAREX_LEX_TOKENKIND_H
#define MAREX_LEX_TOKENKIND_H
#include <cstdint>
#include <string_view>

namespace marex::lex {
enum struct [[nodiscard]] TokenKind : std::uint8_t {
    None = 0,
    Identifier,
    Assignment,
    Print,
    Var,
    Return,

    IntDecl,
    FloatDecl,
    BoolDecl,

    IntLiteral,
    FloatLiteral,
    BoolLiteral,

    Literal,
    Func,
    StatementEnd,

    Arrow,
    FatArrow,

    Match,

    Colon,
    Comma,

    Class,
    Struct,

    OpenBrace,
    CloseBrace,

    OpenBracket,
    CloseBracket,
};

[[nodiscard]] std::string_view operator*(
    TokenKind token_kind);
}  // namespace marex::lex
#endif  // MAREX_LEX_TOKENKIND_H
