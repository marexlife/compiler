#include "Expression.h"

#include <utility>

#include "nodes/Parsable.h"

namespace marex::parse {
Expression::Expression(lex::Token&& token)
    : Parsable(std::move(token)) {}
}  // namespace marex::parse