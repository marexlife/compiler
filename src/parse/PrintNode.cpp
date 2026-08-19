#include "PrintNode.h"
#include <utility>

namespace marex::parse {
PrintNode::PrintNode(lex::Token &&token) : Node(std::move(token)) {}

void PrintNode::print() {
    
}
} // namespace marex::parse