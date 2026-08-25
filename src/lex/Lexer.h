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
    constexpr static std::size_t vector_default_size =
        100;

   public:
    Lexer() = default;
    Lexer(Lexer&&) = delete;
    Lexer& operator=(Lexer&&) = delete;
    Lexer(const Lexer&) = delete;
    Lexer& operator=(const Lexer&) = delete;
    ~Lexer() = default;

    [[nodiscard]] absl::StatusOr<TokenStream> run(
        std::string&& source_text);

   private:
    void push_token(TokenStream& result);
    void reset();
    void push_token_and_current(TokenStream& result,
                                char current);

    TokenFactory token_factory{};
    std::string last_word;
};
}  // namespace marex::lex
#endif  // MAREX_LEXER_LEXER_H
