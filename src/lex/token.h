#ifndef COMPILER_LEX_TOKEN_H_
#define COMPILER_LEX_TOKEN_H_
#include <absl/status/statusor.h>

#include <string>

#include "passkey.h"
#include "token_kind.h"

namespace compiler::lex {
class TokenFactory;
class Token final {
 public:
  Token(core::Passkey<TokenFactory>&& passkey, std::string&& lexeme,
        TokenKind token_kind) noexcept
      : lexeme_(std::move(lexeme)), token_kind_(token_kind) {}

  Token(Token&&) noexcept = default;
  Token& operator=(Token&&) noexcept = default;

  Token(const Token&) = delete;
  Token& operator=(const Token&) = delete;
  ~Token() noexcept = default;

  [[nodiscard]] std::string lexeme() const noexcept { return lexeme_; }
  [[nodiscard]] TokenKind token_kind() const noexcept { return token_kind_; }

 private:
  std::string lexeme_{};
  TokenKind token_kind_{};
};
}  // namespace compiler::lex
#endif  // COMPILER_LEX_TOKEN_H_