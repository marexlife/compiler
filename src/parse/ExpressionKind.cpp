#include "ExpressionKind.h"

#include <source_location>
#include <stdexcept>

#include "nodes/exceptions/InvalidTokenException.h"

namespace marex {
[[nodiscard]] std::string_view parse::operator*(
    ExpressionKind token_kind) {
    switch (token_kind) {
        case ExpressionKind::EmptyType:
            return "void";
        case ExpressionKind::IntType:
            return "int32_t";
        case ExpressionKind::FloatType:
            return "float";
        case ExpressionKind::BoolType:
            return "bool";
        case ExpressionKind::Identifier:
            return "identifier";
        case ExpressionKind::None:
            goto end;
    }

end:
    throw std::out_of_range("Not a valid TypeKind");
}

parse::ExpressionKind parse::from_decl(
    lex::TokenKind token_kind,
    lex::SourcePos source_pos,
    std::source_location cpp_source_location) {
    switch (token_kind) {
        case marex::lex::TokenKind::IntDecl:
            return ExpressionKind::IntType;
        case marex::lex::TokenKind::BoolDecl:
            return ExpressionKind::BoolType;
        case marex::lex::TokenKind::FloatDecl:
            return ExpressionKind::FloatType;
        default:
            throw InvalidTokenException(
                source_pos, token_kind,
                "expected a type",
                cpp_source_location);
    }
}

parse::ExpressionKind parse::from_literal(
    lex::TokenKind token_kind,
    lex::SourcePos source_pos,
    std::source_location cpp_source_location) {
    switch (token_kind) {
        case marex::lex::TokenKind::IntLiteral:
            return ExpressionKind::IntType;
        case marex::lex::TokenKind::BoolLiteral:
            return ExpressionKind::BoolType;
        case marex::lex::TokenKind::FloatLiteral:
            return ExpressionKind::FloatType;
        default:
            throw InvalidTokenException(
                source_pos, token_kind,
                "expected a type",
                cpp_source_location);
    }
}
}  // namespace marex