#ifndef MAREX_PARSE_PARSERPACK_H
#define MAREX_PARSE_PARSERPACK_H
#include <sys/types.h>

#include <string_view>
#include <utility>

#include "SourcePos.h"
#include "Token.h"
#include "TokenKind.h"
#include "TokenStream.h"

namespace marex::parse {
struct ParserPack final {
    explicit ParserPack(lex::TokenStream&& toke_stream)
        : token_stream(std::move(toke_stream)) {}

    void advance() { ++progress; }

    [[nodiscard]] std::size_t get_progress() const {
        return progress;
    }

    [[nodiscard]] std::string_view advance_if_matches(
        lex::TokenKind token);

    [[nodiscard]] lex::TokenKind get_kind() const {
        return get_token().get_kind();
    }

    [[nodiscard]] lex::SourcePos get_pos() const {
        return get_token().get_pos();
    }

    [[nodiscard]] const lex::Token& get_token() const {
        return token_stream.at(progress);
    }

    [[nodiscard]] lex::Token move_out_token() {
        return std::move(token_stream.at(progress));
    }

   private:
    lex::TokenStream token_stream;
    std::size_t progress{};
};
}  // namespace marex::parse
#endif  // MAREX_PARSE_PARSERPACK_H