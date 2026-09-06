#include "VarNode.h"

#include <format>
#include <string>
#include <utility>

#include "ExpressionKind.h"
#include "ParserPack.h"
#include "TokenKind.h"

namespace marex::parse {
VarNode::VarNode(lex::Token&& token)
    : Parsable(std::move(token)) {}

std::string VarNode::as_c() {
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

    type_kind =
        expression_kind_from_literal_or_throw(pack);

    value = pack.get_lexeme();

    pack.advance();
}
}  // namespace marex::parse