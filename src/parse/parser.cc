#include "parser.h"

#include <exception>
#include <memory>
#include <vector>

#include "token.h"
#include "token_kind.h"

namespace compiler::parse {
void Parser::Run(std::vector<lex::Token>&& tokens) {
  std::vector<std::unique_ptr<Node>> result{};

  for (auto& token : tokens) {
    const auto binding_power = token.binding_power();

    if (binding_power > 0) {
    } else {
    }
  }
}

void Parser::VisitToken(lex::Token& token) {
  switch (token.kind()) {
    case lex::TokenKind::kVar:
      break;
    case lex::TokenKind::kIdentifier:
      break;
    case lex::TokenKind::kPrint:
      break;
    case lex::TokenKind::kNone:
      [[fallthrough]];
    default:
      std::terminate();
  }
}
}  // namespace compiler::parse
