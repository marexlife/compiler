#include "OpNode.h"
#include "Node.h"
#include "Token.h"
#include <utility>

namespace marex::parse {
OpNode::OpNode(lex::Token &&token) : AstNode(std::move(token)) {}
} // namespace marex::parse