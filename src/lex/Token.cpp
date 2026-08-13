#include "Token.h"
#include "Logger.h"
#include "TokenKind.h"

namespace marex::lex {
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
} // namespace marex::lex