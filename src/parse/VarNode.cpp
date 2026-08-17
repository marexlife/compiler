#include "VarNode.h"
#include <utility>

namespace marex::parse {
VarNode::VarNode(lex::Token &&token) : Node(std::move(token)) {}
} // namespace marex::parse