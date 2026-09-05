#ifndef MAREX_PARSE_TYPEKIND_H
#define MAREX_PARSE_TYPEKIND_H
#include <cstdint>
#include <source_location>
#include <string_view>

#include "SourcePos.h"
#include "TokenKind.h"

namespace marex::parse {
enum class [[nodiscard]] TypeKind : std::uint8_t {
    None = 0,
    EmptyType,
    IntType,
    BoolType,
    FloatType,
};

[[nodiscard]] std::string_view operator*(
    TypeKind token_kind);

TypeKind type_kind_from_decl(
    lex::TokenKind token_kind,
    lex::SourcePos source_pos,
    std::source_location cpp_source_location =
        std::source_location::current());

TypeKind type_kind_from_literal(
    lex::TokenKind token_kind,
    lex::SourcePos source_pos,
    std::source_location cpp_source_location =
        std::source_location::current());
}  // namespace marex::parse
#endif  // MAREX_PARSE_TYPEKIND_H