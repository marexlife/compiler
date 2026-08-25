#ifndef MAREX_LEX_TOKENFACTORY_H
#define MAREX_LEX_TOKENFACTORY_H
#include <absl/container/flat_hash_map.h>

#include <string_view>

#include "Token.h"
#include "TokenKind.h"

namespace marex::lex {
class TokenFactory final {
   public:
    TokenFactory();

    TokenFactory(TokenFactory&&) = delete;
    TokenFactory& operator=(TokenFactory&&) = delete;
    TokenFactory(const TokenFactory&) = delete;
    TokenFactory& operator=(const TokenFactory&) =
        delete;
    ~TokenFactory() = default;

    [[nodiscard]] Token create_token(
        std::string&& source_word);

   private:
    [[nodiscard]] TokenKind map(
        std::string_view source_word);

    absl::flat_hash_map<std::string_view, TokenKind>
        mapping;
};
}  // namespace marex::lex
#endif  // MAREX_LEX_TOKENFACTORY_H
