#include "TypeKind.h"

#include <stdexcept>

#include "nodes/exceptions/InvalidTokenException.h"

namespace marex {
[[nodiscard]] std::string_view parse::operator*(
    TypeKind token_kind) {
    switch (token_kind) {
        case TypeKind::EmptyType:
            return "void";
        case TypeKind::IntType:
            return "int32_t";
        case TypeKind::FloatType:
            return "float";
        case TypeKind::BoolType:
            return "bool";
        case TypeKind::None:
            goto end;
    }

end:
    throw std::out_of_range("Not a valid TypeKind");
}

parse::TypeKind parse::type_kind_from_decl(
    lex::TokenKind token_kind,
    lex::SourcePos source_pos) {
    switch (token_kind) {
        case marex::lex::TokenKind::IntDecl:
            return TypeKind::IntType;
        case marex::lex::TokenKind::BoolDecl:
            return TypeKind::BoolType;
        case marex::lex::TokenKind::FloatDecl:
            return TypeKind::FloatType;
        default:
            throw InvalidTokenException(
                source_pos, "expected a type");
    }
}

parse::TypeKind parse::type_kind_from_literal(
    lex::TokenKind token_kind,
    lex::SourcePos source_pos) {
    switch (token_kind) {
        case marex::lex::TokenKind::IntLiteral:
            return TypeKind::IntType;
        case marex::lex::TokenKind::BoolLiteral:
            return TypeKind::BoolType;
        case marex::lex::TokenKind::FloatLiteral:
            return TypeKind::FloatType;
        default:
            throw InvalidTokenException(
                source_pos, "expected a type");
    }
}
}  // namespace marex