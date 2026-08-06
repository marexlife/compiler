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
class [[nodiscard]] TokenFactory;
class [[nodiscard]] Token final {
 public:
  Token(core::Passkey<TokenFactory>&& passkey, std::string&& lexeme,
        TokenKind token_kind)
      : lexeme_(std::move(lexeme)), kind_(token_kind) {}

  [[nodiscard]] std::string lexeme() const { return lexeme_; }
  [[nodiscard]] TokenKind kind() const { return kind_; }

  [[nodiscard]] auto binding_power() {
    switch (kind_) {
      case compiler::lex::TokenKind::kPrint:
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
