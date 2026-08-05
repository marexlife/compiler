#include "parser.h"

#include <memory>
#include <vector>

#include "token.h"

namespace compiler::parse {
void Parser::Run(std::vector<lex::Token>&& input) {
  std::vector<std::unique_ptr<Node>> result{};

  const auto binding_powers = std::views::transform(
      input, [](lex::Token& t) { return t.ToBindingPower(); });
}
}  // namespace compiler::parse
