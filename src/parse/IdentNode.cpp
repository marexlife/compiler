#include "IdentNode.h"
#include "Node.h"
#include "ParserPack.h"
#include "Token.h"
#include <string>
#include <utility>

namespace marex::parse {
IdentNode::IdentNode(lex::Token &&token) : Node(std::move(token)) {}

[[nodiscard]] std::string IdentNode::as_string() {
    return std::string{IdentNode::get_lexeme()};
}

void IdentNode::parse([[maybe_unused]] ParserPack &pack) {}
} // namespace marex::parse