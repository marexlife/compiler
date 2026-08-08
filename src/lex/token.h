#ifndef COMPILER_LEX_TOKEN_H_
#define COMPILER_LEX_TOKEN_H_
#include <absl/status/statusor.h>

#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>

#include "passkey.h"
#include "token_kind.h"

namespace compiler::lex {
class TokenFactory;
class [[nodiscard]] Token final {
 public:
  Token(core::Passkey<TokenFactory>&& passkey, std::string&& lexeme,
        TokenKind tokenKind)
      : m_lexeme(std::move(lexeme)), m_kind(tokenKind) {}

  [[nodiscard]] std::string lexeme() const { return m_lexeme; }
  [[nodiscard]] TokenKind kind() const { return m_kind; }

  [[nodiscard]] std::uint8_t binding_power() {
    switch (m_kind) {
      case compiler::lex::TokenKind::Print:
        return 0;
      case compiler::lex::TokenKind::Var:
        return 10;
      case compiler::lex::TokenKind::Identifier:
        return 1;
      case TokenKind::kNone:
        std::cout << "TokenKind is None";
        std::exit(-1);
        break;
      default:
        std::cout << "TokenKind is Invalid";
        std::exit(-1);
        break;
    }
  }

 private:
  std::string m_lexeme;
  TokenKind m_kind{};
};
}  // namespace compiler::lex
#endif  // COMPILER_LEX_TOKEN_H_
