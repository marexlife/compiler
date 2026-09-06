#include "DuoOpNode.h"

#include <utility>

#include "Token.h"
#include "nodes/OpNode.h"

namespace marex::parse {
DuoOpNode::DuoOpNode(lex::Token&& token)
    : OpNode(std::move(token)) {}
}  // namespace marex::parse