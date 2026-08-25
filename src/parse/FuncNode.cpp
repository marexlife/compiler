#include "FuncNode.h"

#include <utility>

#include "Node.h"

namespace marex::parse {
FuncNode::FuncNode(lex::Token&& token)
    : AstNode(std::move(token)) {}

[[nodiscard]] std::string FuncNode::as_string() {
    return "func";
}

void FuncNode::parse(
    [[maybe_unused]] ParserPack& pack) {}
}  // namespace marex::parse
