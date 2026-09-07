#include "AstNode.h"

#include <utility>

#include "Token.h"

namespace marex::parse {
AstNode::AstNode(lex::Token&& token)
    : token(std::move(token)) {}
}  // namespace marex::parse