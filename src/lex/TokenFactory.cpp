#include "TokenFactory.h"

#include <absl/strings/string_view.h>

#include <string_view>

#include "Passkey.h"
#include "Token.h"
#include "TokenKind.h"

namespace marex::lex {
Token TokenFactory::create_token(std::string &&source_word) {
    return Token{
        core::Passkey<TokenFactory>{},
        std::move(source_word),
        map(source_word),
    };
}

[[nodiscard]] TokenKind
TokenFactory::map(std::string_view source_word) {
    if (mapping.contains(source_word)) {
        return mapping.at(source_word);
    }

    return TokenKind::Identifier;
}
} // namespace marex::lex
