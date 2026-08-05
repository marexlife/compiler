#include "parser.h"

#include <algorithm>
#include <cstdint>
#include <exception>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>

#include "nodes/ident_node.h"
#include "nodes/print_node.h"
#include "nodes/var_node.h"
#include "token.h"
#include "token_kind.h"

namespace compiler::parse {
void Parser::Run() {}

std::vector<std::unique_ptr<nodes::Node>>
Parser::TransformToNodeVector(std::vector<lex::Token>&& input) {
  std::vector<std::unique_ptr<nodes::Node>> result{};

  const auto binding_powers = std::views::transform(
      input, [](lex::Token& e) { return e.ToBindingPower(); });

  return result;
}

std::unique_ptr<nodes::Node> Parser::TransformToNode(
    lex::Token& input) {
  switch (input.token_kind()) {
    case lex::TokenKind::kIdentifier:
      return std::make_unique<nodes::IdentNode>(input.lexeme());
    case lex::TokenKind::kPrint:
      return std::make_unique<nodes::PrintNode>();
    case lex::TokenKind::kVar:
      return std::make_unique<nodes::VarNode>();
    default:
      std::unreachable();
  }
}
}  // namespace compiler::parse
