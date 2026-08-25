#ifndef MAREX_PARSE_PARSERPACK_H
#define MAREX_PARSE_PARSERPACK_H
#include "Token.h"
#include "TokenKind.h"
#include "TokenStream.h"
#include "absl/status/statusor.h"
#include <string_view>
#include <sys/types.h>
#include <utility>

namespace marex::parse {
struct ParserPack final {
    explicit ParserPack(lex::TokenStream &&toke_stream)
        : token_stream(std::move(toke_stream)) {}

    void advance() { ++progress; }

    [[nodiscard]] std::size_t get_progress() const {
        return progress;
    }

    [[nodiscard]] absl::StatusOr<std::string_view>
    advance_if_matches(lex::TokenKind token_kind);

    [[nodiscard]] lex::TokenKind get_kind() const {
        return get_token().get_kind();
    }

    [[nodiscard]] const lex::Token &get_token() const {
        return token_stream.at(progress);
    }

    [[nodiscard]] lex::Token move_out_token() {
        return std::move(token_stream.at(progress));
    }

  private:
    lex::TokenStream token_stream;
    std::size_t progress{};
};
} // namespace marex::parse
#endif // MAREX_PARSE_PARSERPACK_H