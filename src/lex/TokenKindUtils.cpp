#include <string_view>

#include "Logger.h"
#include "TokenKind.h"
#include "TokenKindUitls.h"

namespace marex {
[[nodiscard]] std::string_view lex::operator*(
    TokenKind token_kind) {
    switch (token_kind) {
        case TokenKind::Func:
            return "function keyword";
        case TokenKind::Colon:
            return ":";
        case TokenKind::Identifier:
            return "identifier";
        case TokenKind::Literal:
            return "Literal";
        case TokenKind::IntDecl:
            return "Int Decl";
        case TokenKind::FloatDecl:
            return "Float Decl";
        case lex::TokenKind::BoolDecl:
            return "Bool Decl";
        case lex::TokenKind::IntLiteral:
            return "Int Literal";
        case lex::TokenKind::FloatLiteral:
            return "Int Literal";
        case lex::TokenKind::BoolLiteral:
            return "Bool Literal";
        case lex::TokenKind::Arrow:
            return "arrow";
        case lex::TokenKind::FatArrow:
            return "fat arrow";
        case marex::lex::TokenKind::Match:
            return "match";
        case marex::lex::TokenKind::Comma:
            return "comma";
        case TokenKind::Print:
            return "print";
        case TokenKind::Assignment:
            return "=";
        case TokenKind::StatementEnd:
            return ";";
        case TokenKind::Var:
            return "var";
        case TokenKind::Class:
            return "Class";
        case TokenKind::Struct:
            return "Struct";
        case TokenKind::OpenBrace:
            return "{";
        case TokenKind::CloseBrace:
            return "}";
        case TokenKind::OpenBracket:
            return "(";
        case TokenKind::CloseBracket:
            return ")";
        case TokenKind::Return:
            return "return";
        case TokenKind::None:
            goto end;
    }

end:
    core::Logger::log_fatal_internal_error(
        "Out of range TokenKind");
}
}  // namespace marex
