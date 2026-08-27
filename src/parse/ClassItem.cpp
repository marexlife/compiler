#include "ClassItem.h"

#include <utility>

#include "Node.h"
#include "Token.h"

namespace marex::parse {
ClassItem::ClassItem(lex::Token&& token)
    : AstNode(std::move(token)) {}
}  // namespace marex::parse