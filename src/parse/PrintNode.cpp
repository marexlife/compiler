#include "PrintNode.h"
#include <utility>

namespace marex::parse {
PrintNode::PrintNode(lex::Token &&token) : Node(std::move(token)) {}
} // namespace marex::parse