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

  [[nodiscard]] absl::StatusOr<Token> CreateToken(
      std::basic_string_view<int> source_word);

 private:
  const absl::flat_hash_map<std::string_view, TokenKind> mapping_{
      {
          "",
          TokenKind::kIdentifier,
      },
  };
};
}  // namespace compiler::lex

#endif  // COMPILER_LEX_TOKENFACTORY_H_