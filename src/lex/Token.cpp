#include "Token.h"
#include "Logger.h"
#include "TokenKind.h"
#include <utility>

namespace marex::lex {
Token::Token([[maybe_unused]] core::Passkey<TokenFactory> &&passkey,
             std::string &&lexeme, TokenKind tokenKind)
    : lexeme(std::move(lexeme)), kind(tokenKind) {}

[[nodiscard]] std::uint8_t Token::getBindingPower() const {
    switch (kind) {
    case lex::TokenKind::Print: {
        static const std::uint8_t bindingPower = 100;

        return bindingPower;
    } break;
    case lex::TokenKind::Var: {
        static const std::uint8_t bindingPower = 30;

        return bindingPower;
    } break;
    case lex::TokenKind::Identifier: {
        static const std::uint8_t bindingPower = 10;

        return bindingPower;
    } break;
    case TokenKind::None:
        core::Logger::logFatalError("TokenKind is none");
    default:
        core::Logger::logFatalError("TokenKind is Invalid");
    }

    core::Logger::logFatalError("No Token selected");
}

[[nodiscard]] std::string_view Token::getLexeme() {
    if (!lexeme) [[unlikely]] {
        core::Logger::logFatalInternalError(
            "trying to get lexeme when none is there");
    }

    return *lexeme;
}

[[nodiscard]] std::string Token::moveOutLexeme() {
    if (!lexeme) [[unlikely]] {
        core::Logger::logFatalInternalError(
            "trying to move out a lexeme when none exists");
    }

    return *lexeme;
}
} // namespace marex::lex