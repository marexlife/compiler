#ifndef COMPILER_LEX_TOKEN_H
#define COMPILER_LEX_TOKEN_H
#include <absl/status/statusor.h>

#include "passkey.h"
#include "token_kind.h"
#include <cstdlib>
#include <iostream>
#include <spdlog/spdlog.h>
#include <string>

namespace compiler::lex {
class TokenFactory;

class [[nodiscard]] Token final {
public:
    Token(core::Passkey<TokenFactory>&& passkey, std::string&& lexeme,
        TokenKind tokenKind)
        : lexeme(std::move(lexeme))
        , kind(tokenKind)
    {
    }

    [[nodiscard]] std::string getLexeme() const { return lexeme; }

    [[nodiscard]] TokenKind getKind() const { return kind; }

    [[nodiscard]] std::uint8_t getBindingPower() const
    {
        switch (kind) {
        case compiler::lex::TokenKind::Print:
            return 0;
        case compiler::lex::TokenKind::Var:
            return 10;
        case compiler::lex::TokenKind::Identifier:
            return 1;
        case TokenKind::None:
            std::cout << "TokenKind is None";
            std::exit(-1);
            break;
        default:
            std::cout << "TokenKind is Invalid";
            std::exit(-1);
            break;
        }
    }

private:
    std::string lexeme;
    TokenKind kind { };
};
} // namespace compiler::lex
#endif // COMPILER_LEX_TOKEN_H
