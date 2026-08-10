#ifndef COMPILER_LEX_TOKEN_H
#define COMPILER_LEX_TOKEN_H
#include <absl/status/statusor.h>

#include <cstdlib>
#include <iostream>
#include <string>

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

    [[nodiscard]] auto getBindingPower() {
        switch (kind) {
        case compiler::lex::TokenKind::Print:
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
    TokenKind kind{};
};
} // namespace compiler::lex
#endif // COMPILER_LEX_TOKEN_H
