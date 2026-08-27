#ifndef MAREX_LEX_LEXER_H
#define MAREX_LEX_LEXER_H
#include <absl/container/inlined_vector.h>
#include <absl/strings/string_view.h>

#include <cstddef>
#include <string>

#include "LastCharKind.h"
#include "TokenFactory.h"
#include "TokenStream.h"

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

    [[nodiscard]] TokenStream run(
        std::string&& source_text);

   private:
    void push_token(TokenStream& result);
    void reset();
    void push_current(TokenStream& result,
                      char current);
    void push_token_and_current(TokenStream& result,
                                char current);

    [[nodiscard]] bool is_flushable() const {
        return last_char_kind ==
               LastCharKind::WasDefault;
    }

    std::optional<char> last_char_optional =
        std::nullopt;
    LastCharKind last_char_kind = LastCharKind::None;
    TokenFactory token_factory{};
    std::string last_word;
};
}  // namespace marex::lex
#endif  // MAREX_LEXER_LEXER_H
