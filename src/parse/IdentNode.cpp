#include "IdentNode.h"
#include "JumpCont.h"
#include "Node.h"
#include "Token.h"
#include <string>
#include <utility>

namespace marex::parse {
IdentNode::IdentNode(lex::Token &&token) : Node(std::move(token)) {}

[[nodiscard]] std::string IdentNode::as_string() {
    return std::string{IdentNode::get_lexeme()};
}

[[nodiscard]] JumpCount parse_print() { return 1; }
} // namespace marex::parse