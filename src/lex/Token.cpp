#include "Token.h"
#include "Logger.h"
#include "TokenKind.h"
#include <utility>

namespace marex::lex {
Token::Token([[maybe_unused]] core::Passkey<TokenFactory> &&passkey,
             std::string &&lexeme, TokenKind token_kind)
    : lexeme(std::move(lexeme)), kind(token_kind) {}

[[nodiscard]] std::uint8_t Token::get_binding_power() const {
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
        core::Logger::log_fatal_error("TokenKind is none");
    default:
        core::Logger::log_fatal_error("TokenKind is Invalid");
    }

    core::Logger::log_fatal_error("No Token selected");
}

[[nodiscard]] std::string_view Token::get_lexeme() const {
    if (!lexeme) [[unlikely]] {
        core::Logger::log_fatal_internal_error(
            "trying to get lexeme when none is there");
    }

    return *lexeme;
}

[[nodiscard]] std::string Token::move_out_lexeme() {
    if (!lexeme) [[unlikely]] {
        core::Logger::log_fatal_internal_error(
            "trying to move out a lexeme when none exists");
    }

    return *lexeme;
}
} // namespace marex::lex