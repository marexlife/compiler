#include "VarNode.h"
#include <utility>

namespace marex::parse {
VarNode::VarNode(lex::Token &&token) : Node(std::move(token)) {}

void VarNode::print() {}
} // namespace marex::parse