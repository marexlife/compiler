#ifndef COMPILER_LEX_TOKEN_H_
#define COMPILER_LEX_TOKEN_H_
#include <absl/status/statusor.h>

#include <string>

#include "passkey.h"
#include "token_kind.h"

namespace compiler::lex {
class [[nodiscard]] TokenFactory;
class [[nodiscard]] Token final {
 public:
  Token(core::Passkey<TokenFactory>&& passkey, std::string&& lexeme,
        TokenKind token_kind)
      : lexeme_(std::move(lexeme)), token_kind_(token_kind) {}

  Token(Token&&) = default;
  Token& operator=(Token&&) = default;

  Token(const Token&) = delete;
  Token& operator=(const Token&) = delete;
  ~Token() = default;

  [[nodiscard]] std::string lexeme() const { return lexeme_; }
  [[nodiscard]] TokenKind token_kind() const { return token_kind_; }

  [[nodiscard]] std::uint8_t ToBindingPower();

 private:
  std::string lexeme_;
  TokenKind token_kind_{};
};
}  // namespace compiler::lex
#endif  // COMPILER_LEX_TOKEN_H_
