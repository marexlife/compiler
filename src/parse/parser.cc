#include "parser.h"

#include <exception>
#include <memory>
#include <vector>

#include "token.h"
#include "token_kind.h"
#include "token_stream.h"

namespace compiler::parse {
void Parser::Run(lex::TokenStream&& tokens) {
  Node result{};

  for (auto& token : tokens) {
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
