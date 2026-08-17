#include "Node.h"
#include "Token.h"
#include <utility>

namespace marex::parse {
Node::Node(lex::Token &&token) : token(std::move(token)) {}
} // namespace marex::parse