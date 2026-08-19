#include "OpNode.h"
#include "Node.h"
#include "Token.h"
#include <utility>

namespace marex::parse {
OpNode::OpNode(lex::Token &&token) : Node(std::move(token)) {}
} // namespace marex::parse