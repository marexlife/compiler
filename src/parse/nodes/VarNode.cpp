#include "VarNode.h"

#include <format>
#include <string>
#include <utility>

#include "ParserPack.h"
#include "TokenKind.h"
#include "TypeKind.h"
#include "nodes/FileItem.h"

namespace marex::parse {
VarNode::VarNode(lex::Token&& token)
    : FileItem(std::move(token)) {}

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
        from_literal(pack.get_kind(), pack.get_pos());

    value = pack.get_lexeme();

    pack.advance();
}
}  // namespace marex::parse