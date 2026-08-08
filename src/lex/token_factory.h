#ifndef COMPILER_LEX_TOKENFACTORY_H
#define COMPILER_LEX_TOKENFACTORY_H
#include <absl/container/flat_hash_map.h>

#include <string_view>

#include "token.h"
#include "token_kind.h"

namespace compiler::lex {
class TokenFactory final {
public:
    TokenFactory()
        : mapping({
              { "print", TokenKind::Print },
              { "var", TokenKind::Var },
          })
    {
    }

    TokenFactory(TokenFactory&&) = delete;
    TokenFactory& operator=(TokenFactory&&) = delete;
    TokenFactory(const TokenFactory&) = delete;
    TokenFactory& operator=(const TokenFactory&) = delete;
    ~TokenFactory() = default;

    [[nodiscard]] Token createToken(std::string&& sourceWord);

private:
    [[nodiscard]] TokenKind map(std::string_view sourceWord);

    absl::flat_hash_map<std::string_view, TokenKind> mapping;
};
} // namespace compiler::lex
#endif // COMPILER_LEX_TOKENFACTORY_H
