#ifndef COMPILER_LEX_TOKEN_H
#define COMPILER_LEX_TOKEN_H
#include <absl/status/statusor.h>

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>
#include <string_view>

#include "Logger.h"
#include "Passkey.h"
#include "TokenKind.h"

namespace compiler::lex {
class [[nodiscard]] TokenFactory;
class [[nodiscard]] Token final {
  public:
    Token(core::Passkey<TokenFactory> &&passkey, std::string &&lexeme,
          TokenKind tokenKind)
        : lexeme(std::move(lexeme)), kind(tokenKind) {}

    [[nodiscard]] std::string getLexeme() const { return lexeme; }
    [[nodiscard]] TokenKind getKind() const { return kind; }

    [[nodiscard]] std::uint8_t getBindingPower() const {
        switch (kind) {
        case compiler::lex::TokenKind::Print: {
            static const std::uint8_t bindingPower = 100;

            return bindingPower;
        } break;
        case compiler::lex::TokenKind::Var: {
            static const std::uint8_t bindingPower = 30;

            return bindingPower;
        } break;
        case compiler::lex::TokenKind::Identifier: {
            static const std::uint8_t bindingPower = 10;

            return bindingPower;
        } break;
        case TokenKind::None:
            core::Logger::logFatal(
                std::string_view{"TokenKind is none"});
            break;
        default:
            core::Logger::logFatal(
                std::string_view{"TokenKind is Invalid"});
            std::exit(-1);
            break;
        }

        core::Logger::logFatal(std::string_view{"No Token selected"});
    }

  private:
    std::string lexeme;
    TokenKind kind{};
};
} // namespace compiler::lex
#endif // COMPILER_LEX_TOKEN_H
