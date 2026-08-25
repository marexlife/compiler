#include "Node.h"
#include "Token.h"
#include <utility>

namespace marex::parse {
AstNode::AstNode(lex::Token &&token) : token(std::move(token)) {}
} // namespace marex::parse