#include "OpNode.h"
#include "Node.h"
#include "Token.h"

namespace marex::parse {
OpNode::OpNode(lex::Token &token) : Node(token) {}
} // namespace marex::parse