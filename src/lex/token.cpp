#include "token.h"

namespace compiler::lex {
std::uint8_t Token::ToBindingPower(lex::Token& token) {
  switch (token.token_kind()) {
    case lex::TokenKind::Variable:
      return 127;
    case lex::TokenKind::Print:
      return 90;
    case lex::TokenKind::Identifier:
      return 0;
    default:
      std::cout << "Error\n";
      std::terminate();
      break;
  }
}
}  // namespace compiler::lex
