#ifndef COMPILER_LEX_TOKENFACTORY_H_
#define COMPILER_LEX_TOKENFACTORY_H_
#include <absl/container/flat_hash_map.h>

#include <string_view>

#include "token.h"
#include "token_kind.h"

namespace compiler::lex {
class TokenFactory final {
 public:
  TokenFactory() = default;
  TokenFactory(TokenFactory&&) = delete;
  TokenFactory& operator=(TokenFactory&&) = delete;
  TokenFactory(const TokenFactory&) = delete;
  TokenFactory& operator=(const TokenFactory&) = delete;
  ~TokenFactory() = default;

  [[nodiscard]] Token CreateToken(std::string&& source_word);

 private:
  [[nodiscard]] TokenKind Map(std::string_view source_word);

  const absl::flat_hash_map<std::string_view, TokenKind> mapping_{

  };
};
}  // namespace compiler::lex

#endif  // COMPILER_LEX_TOKENFACTORY_H_