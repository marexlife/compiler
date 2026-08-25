#include "IdentNode.h"

#include <string>
#include <utility>

#include "Node.h"
#include "ParserPack.h"
#include "Token.h"
#include "TokenKind.h"

namespace marex::parse {
IdentNode::IdentNode(lex::Token&& token)
    : AstNode(std::move(token)) {}

[[nodiscard]] std::string IdentNode::as_string() {
    return std::string{IdentNode::get_lexeme()};
}

void IdentNode::parse(
    [[maybe_unused]] ParserPack& pack) {
    value =
        pack.advance_if_matches(lex::TokenKind::Ident);
}
}  // namespace marex::parse