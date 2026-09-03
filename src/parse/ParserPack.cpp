#include "ParserPack.h"

#include <format>
#include <string_view>
#include <utility>

#include "Logger.h"
#include "TokenKind.h"
#include "TokenKindUitls.h"
#include "exceptions/InvalidTokenException.h"

namespace marex::parse {
ParserPack::ParserPack(lex::TokenStream&& token_stream)
    : token_stream(std::move(token_stream)) {}

std::string_view ParserPack::get_kind_string() const {
    return lex::token_kind_to_string(get_kind());
}

std::string ParserPack::advance_if_matches_or_throw(
    lex::TokenKind token_kind) {
    auto pre_increment_token_borrow = get_token();
    const auto got_token_kind =
        pre_increment_token_borrow.get_kind();

    if (got_token_kind == token_kind) {
        advance();

        core::Logger::log_info(std::format(
            "TokenKind {} matched",
            lex::token_kind_to_string(token_kind)));

        return pre_increment_token_borrow
            .move_out_lexeme();
    }

    throw exceptions::InvalidTokenException(
        get_pos(), token_kind, got_token_kind);
}

bool ParserPack::is_at_end() const {
    const auto is_finished =
        token_stream.size() <= progress;

    core::Logger::log_info(
        std::format("ParserPack: is_finished = {}",
                    is_finished ? "true" : "false"));

    return is_finished;
}

[[nodiscard]] std::string
ParserPack::get_error_message() const {
    return std::format(
        "invalid Token: '{}' at '{}'",
        lex::token_kind_to_string(get_kind()),
        get_pos().to_string());
}
}  // namespace marex::parse
