#include "Node.h"

namespace marex::parse {
Node::Node(lex::Token &token)
    : bindingPower(token.GetBindingPower()) {}

std::uint8_t Node::getBindingPower() const { return bindingPower; }

void Node::setBindingPower(std::uint8_t bindingPower) {
    this->bindingPower = bindingPower;
}
} // namespace marex::parse