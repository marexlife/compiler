#include "token.h"

#include <optional>

namespace compiler::lex {
std::optional<std::uint8_t> Token::binding_power() {
  switch (kind()) {
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
