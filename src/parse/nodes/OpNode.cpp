#include "OpNode.h"

namespace marex::parse {
OpNode::OpNode(lex::Token&& token)
    : Expression(std::move(token)) {}
}  // namespace marex::parse