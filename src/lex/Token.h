#ifndef MAREX_LEX_TOKEN_H
#define MAREX_LEX_TOKEN_H
#include <absl/status/statusor.h>

#include <cstdlib>
#include <string>
#include <string_view>

#include "Passkey.h"
#include "TokenKind.h"

namespace marex::lex {
class [[nodiscard]] TokenFactory;
class [[nodiscard]] Token final {
  public:
    Token([[maybe_unused]] core::Passkey<TokenFactory> &&passkey,
          std::string &&lexeme, TokenKind tokenKind)
        : lexeme(std::move(lexeme)), kind(tokenKind) {}

    [[nodiscard]] std::string_view getLexeme() const {
        return lexeme;
    }
    [[nodiscard]] TokenKind getKind() const { return kind; }

    [[nodiscard]] std::uint8_t getBindingPower() const;

  private:
    std::string lexeme;
    TokenKind kind{};
};
} // namespace marex::lex
#endif // MAREX_LEX_TOKEN_H
