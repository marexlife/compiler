#include "VarNode.h"

#include <format>
#include <functional>
#include <string>
#include <utility>

#include "ParserPack.h"
#include "TokenKind.h"
#include "TypeKind.h"
#include "exceptions/InvalidTokenException.h"
#include "nodes/FileItem.h"

namespace marex::parse {
VarNode::VarNode(lex::Token&& token)
    : FileItem(std::move(token)) {}

std::string VarNode::as_string() {
    return std::format("{} {} = {};\n", *type_kind,
                       name, value);
}

void VarNode::parse(ParserPack& pack) {
    pack.advance_if_matches_or_throw(
        lex::TokenKind::Var);
    name = pack.advance_if_matches_or_throw(
        lex::TokenKind::Identifier);
    pack.advance_if_matches_or_throw(
        lex::TokenKind::Assignment);

    type_kind = std::invoke([&] {
        switch (pack.get_kind()) {
            case lex::TokenKind::FloatLiteral:
                return TypeKind::FloatType;
            case lex::TokenKind::BoolLiteral:
                return TypeKind::BoolType;
            case lex::TokenKind::IntLiteral:
                return TypeKind::IntType;
            default:
                throw InvalidTokenException(
                    pack.get_pos(),
                    "unsupported value");
        }
    });

    value = pack.get_lexeme();

    pack.advance();
}
}  // namespace marex::parse