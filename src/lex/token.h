#ifndef COMPILER_LEX_TOKEN_H_
#define COMPILER_LEX_TOKEN_H_
#include <absl/status/statusor.h>

#include <string>

#include "token_kind.h"

namespace compiler::lex {
class Token final {
 public:
  Token(Token&&) = delete;
  Token& operator=(Token&&) = delete;
  Token(const Token&) = delete;
  Token& operator=(const Token&) = delete;
  ~Token() = default;

  [[nodiscard]] std::basic_string<int> lexeme() const { return lexeme_; }
  [[nodiscard]] TokenKind token_kind() const { return token_kind_; }

 private:
  Token(std::basic_string<int>&& lexeme, TokenKind token_kind)
      : lexeme_(std::move(lexeme)), token_kind_(token_kind) {}

  std::basic_string<int> lexeme_{};
  TokenKind token_kind_{};
};
}  // namespace compiler::lex
#endif  // COMPILER_LEX_TOKEN_H_