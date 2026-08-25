#include "ClassNode.h"

#include <utility>

#include "Node.h"
#include "TokenKind.h"

namespace marex::parse {
ClassNode::ClassNode(lex::Token&& token)
    : AstNode(std::move(token)) {}

[[nodiscard]] std::string ClassNode::as_string() {
    return class_name;
}

void ClassNode::parse(ParserPack& pack) {
    pack.advance_if_matches(lex::TokenKind::Class);
}
}  // namespace marex::parse