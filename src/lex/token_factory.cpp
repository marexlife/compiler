#include "token_factory.h"

#include <absl/strings/string_view.h>

#include <string_view>

#include "passkey.h"
#include "token.h"
#include "token_kind.h"

namespace compiler::lex 
{
Token TokenFactory::createToken(std::string&& sourceWord) 
{
    return Token{
        core::Passkey<TokenFactory>{},
        std::move(sourceWord),
        map(sourceWord),
    };
}

[[nodiscard]] TokenKind TokenFactory::map(
    std::string_view sourceWord) 
{
    if (mapping_.contains(sourceWord)) {
        return mapping_.at(sourceWord);
    } else {
        return TokenKind::Identifier;
    }
}
}  // namespace compiler::lex
