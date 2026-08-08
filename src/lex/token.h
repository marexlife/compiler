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
        TokenKind token_kind)
      : lexeme_(std::move(lexeme)), kind_(token_kind) {}

  [[nodiscard]] std::string lexeme() const { return lexeme_; }
  [[nodiscard]] TokenKind kind() const { return kind_; }

  [[nodiscard]] std::uint8_t binding_power() {
    switch (kind_) {
      case compiler::lex::TokenKind::kPrint:
        return 0;
      case compiler::lex::TokenKind::kVar:
        return 10;
      case compiler::lex::TokenKind::kIdentifier:
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
  std::string lexeme_;
  TokenKind kind_{};
};
}  // namespace compiler::lex
#endif  // COMPILER_LEX_TOKEN_H_
