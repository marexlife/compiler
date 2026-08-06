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
      : lexeme_(std::move(lexeme)), kind_(token_kind) {}

  Token(Token&&) = default;
  Token& operator=(Token&&) = default;

  Token(const Token&) = delete;
  Token& operator=(const Token&) = delete;
  ~Token() = default;

  [[nodiscard]] std::string lexeme() const { return lexeme_; }
  [[nodiscard]] TokenKind kind() const { return kind_; }

  [[nodiscard]] std::optional<std::uint8_t> binding_power();

 private:
  std::string lexeme_;
  TokenKind kind_{};
};
}  // namespace compiler::lex
#endif  // COMPILER_LEX_TOKEN_H_
