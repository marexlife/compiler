#include "TokenFactory.h"

#include <absl/strings/string_view.h>

#include <string_view>

#include "Passkey.h"
#include "Token.h"
#include "TokenKind.h"

namespace compiler::lex {
Token TokenFactory::createToken(std::string&& sourceWord)
{
    return Token {
        core::Passkey<TokenFactory> { },
        std::move(sourceWord),
        map(sourceWord),
    };
}

[[nodiscard]] TokenKind TokenFactory::map(std::string_view sourceWord)
{
    if (mapping.contains(sourceWord)) {
        return mapping.at(sourceWord);
    }

    return TokenKind::Identifier;
}
} // namespace compiler::lex
