#include "parser.h"

#include <algorithm>
#include <cstdint>
#include <exception>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>

#include "token.h"
#include "token_kind.h"

namespace compiler::parse {
void Parser::Run() {}

std::vector<std::unique_ptr<Node>> Parser::TransformToNodeVector(
    std::vector<lex::Token>&& input) {
  std::vector<std::unique_ptr<Node>> result{};

  const auto binding_powers = std::views::transform(
      input, [](lex::Token& e) { return e.ToBindingPower(); });

  return result;
}
}  // namespace compiler::parse
