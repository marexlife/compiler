#include "Expression.h"

#include <utility>

#include "nodes/AstNode.h"

namespace marex::parse {
Expression::Expression(lex::Token&& token)
    : AstNode(std::move(token)) {}
}  // namespace marex::parse