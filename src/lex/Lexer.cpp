#include "Lexer.h"

#include <optional>
#include <string>

#include "Defer.h"
#include "LastCharKind.h"
#include "Token.h"
#include "TokenStream.h"
#include "exceptions/SourceCodeEmptyException.h"

namespace marex::lex {
TokenStream Lexer::run(std::string&& source_text) {
    TokenStream result;

    core::Defer defer_reset = [&]() { reset(); };

    result.reserve(vector_default_size);

    std::optional<char> last_char_optional =
        std::nullopt;
    LastCharKind last_char_kind = LastCharKind::None;

    for (const auto source_text_char : source_text) {
        LastCharKind this_char_kind =
            LastCharKind::WasNotDefault;

        core::Defer defer_iter_end = [&]() {
            last_char_optional = source_text_char;
            last_char_kind = this_char_kind;
        };

        switch (source_text_char) {
            case ' ':
                if (last_char_kind ==
                    LastCharKind::WasDefault) {
                    Lexer::push_token(result);
                }
                break;
            case ';' | ':' | '\n' | '\0':
                if (last_char_kind ==
                    LastCharKind::WasDefault) {
                    Lexer::push_token_and_current(
                        result, source_text_char);
                } else {
                    Lexer::push_token(result);
                }
                break;
            default:
                this_char_kind =
                    LastCharKind::WasDefault;
                last_word.push_back(source_text_char);
                break;
        }
    }

    if (!last_char_optional.has_value()) [[unlikely]] {
        throw SourceCodeEmptyException();
    }

    return result;
}

void Lexer::reset() { last_word.clear(); }

void Lexer::push_token(TokenStream& result) {
    result.emplace_back(token_factory.create_token(
        std::string{last_word}));

    last_word.clear();
}

void Lexer::push_current(TokenStream& result,
                         char current) {
    result.emplace_back(token_factory.create_token(
        std::string{current}));
}

void Lexer::push_token_and_current(TokenStream& result,
                                   char current) {
    push_token(result);
    push_current(result, current);
}
}  // namespace marex::lex
