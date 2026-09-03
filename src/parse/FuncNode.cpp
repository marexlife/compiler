#include "FuncNode.h"

#include <functional>
#include <print>
#include <utility>

#include "FileItem.h"
#include "ParserPack.h"
#include "TokenKind.h"
#include "TypeKind.h"
#include "exceptions/InvalidTokenException.h"

namespace marex::parse {
FuncNode::FuncNode(lex::Token&& token)
    : FileItem(std::move(token)) {}

[[nodiscard]] std::string FuncNode::as_string() {
    return "func node";
}

void FuncNode::parse(ParserPack& pack) {
    parse_func_signature(pack);
    parse_func_body(pack);
}

void FuncNode::parse_func_signature(ParserPack& pack) {
    pack.advance_if_matches_or_throw(
        lex::TokenKind::Func);
    pack.advance_if_matches_or_throw(
        lex::TokenKind::Identifier);
    pack.advance_if_matches_or_throw(
        lex::TokenKind::OpenBracket);
    pack.advance_if_matches_or_throw(
        lex::TokenKind::CloseBracket);

    if (pack.advance_if_matches(
            lex::TokenKind::OpenBrace)) {
        type_kind = TypeKind::EmptyType;
        return;
    }

    pack.advance_if_matches_or_throw(
        lex::TokenKind::Arrow);

    type_kind = std::invoke([&] {
        pack.advance();

        switch (pack.get_kind()) {
            case marex::lex::TokenKind::IntDecl:
                return TypeKind::IntType;
            case marex::lex::TokenKind::BoolDecl:
                return TypeKind::BoolType;
            case marex::lex::TokenKind::FloatDecl:
                return TypeKind::FloatType;
            default:
                throw exceptions::
                    InvalidTokenException(
                        pack.get_pos(),
                        "expected a type");
        }
    });

    pack.advance_if_matches_or_throw(
        lex::TokenKind::OpenBrace);
}

void FuncNode::parse_func_body(ParserPack& pack) {
    pack.advance_if_matches_or_throw(
        lex::TokenKind::CloseBrace);
}
}  // namespace marex::parse
