#ifndef MAREX_PARSE_PARSERPACK_H
#define MAREX_PARSE_PARSERPACK_H
#include <cstddef>
#include <iostream>
#include <string>
#include <string_view>

#include "SourcePos.h"
#include "Token.h"
#include "TokenKind.h"
#include "TokenStream.h"

namespace marex::parse {
struct ParserPack final {
    explicit ParserPack(
        lex::TokenStream&& token_stream);

    void advance() { ++progress; }

    [[nodiscard]] bool is_at_end() const;

    [[nodiscard]] std::size_t get_progress() const {
        return progress;
    }

    [[nodiscard]] std::string_view get_kind_string()
        const;

    [[nodiscard]] bool matches(
        lex::TokenKind token_kind) const {
        return get_kind() == token_kind;
    }

    /* NOT [[nodiscard]] */ std::string
    advance_if_matches(lex::TokenKind token_kind);

    [[nodiscard]] lex::TokenKind get_kind() const {
        return get_token().get_kind();
    }

    [[nodiscard]] lex::SourcePos get_pos() const {
        return get_token().get_pos();
    }

    [[nodiscard]] const lex::Token& get_token() const {
        return token_stream.at(progress);
    }

    [[nodiscard]] lex::Token copy_out_token() {
        std::cin.get();

        return lex::Token(token_stream.at(progress));
    }

    [[nodiscard]] std::string get_error_message()
        const;

   private:
    lex::TokenStream token_stream;
    std::size_t progress{};
};
}  // namespace marex::parse
#endif  // MAREX_PARSE_PARSERPACK_H
