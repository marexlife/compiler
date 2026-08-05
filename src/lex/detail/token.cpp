#include "token.h"

namespace compiler::lex {
std::uint8_t Token::ToBindingPower(lex::Token& token) {
  switch (token.token_kind()) {
    case lex::TokenKind::kVar:
      return 127;
    case lex::TokenKind::kPrint:
      return 90;
    case lex::TokenKind::kIdentifier:
      return 0;
    default:
      std::cout << "Error\n";
      std::terminate();
      break;
  }
}
}  // namespace compiler::lex
