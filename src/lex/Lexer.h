#ifndef MAREX_LEX_LEXER_H
#define MAREX_LEX_LEXER_H
#include <absl/container/inlined_vector.h>
#include <absl/strings/string_view.h>

#include <cstddef>
#include <string>

#include "TokenFactory.h"
#include "TokenStream.h"
#include "absl/status/statusor.h"

namespace marex::lex {
class [[nodiscard]] Lexer final {
    static constexpr std::size_t vectorDefaultSize = 10;

  public:
    Lexer() = default;
    Lexer(Lexer &&) = delete;
    Lexer &operator=(Lexer &&) = delete;
    Lexer(const Lexer &) = delete;
    Lexer &operator=(const Lexer &) = delete;
    ~Lexer() = default;

    [[nodiscard]] absl::StatusOr<TokenStream>
    run(std::string &&sourceText);

  private:
    void pushToken();
    void pushStatement(TokenStream &result);
    void reset();

    TokenFactory tokenFactory{};
    Statement lastStatement;
    std::string lastWord;
};
} // namespace marex::lex
#endif // MAREX_LEXER_LEXER_H
