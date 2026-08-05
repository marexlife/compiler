#include "parser.h"

#include <memory>
#include <vector>

#include "token.h"

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
