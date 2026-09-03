#include "ParserPack.h"

#include <format>
#include <string_view>
#include <utility>

#include "Logger.h"
#include "TokenKind.h"
#include "TokenKindUitls.h"
#include "nodes/exceptions/InvalidTokenException.h"

namespace marex::parse {
ParserPack::ParserPack(lex::TokenStream&& token_stream)
    : ParserPack(std::move(token_stream), {}) {}

ParserPack::ParserPack(lex::TokenStream&& token_stream,
                       bool is_in_lint_mode)
    : token_stream(std::move(token_stream)),
      progress(),
      is_in_lint_mode(is_in_lint_mode) {}

std::string_view ParserPack::get_kind_string() const {
    return *get_kind();
}

[[nodiscard]] bool ParserPack::advance_if_matches(
    lex::TokenKind token_kind) {
    const auto does_match = matches(token_kind);

    if (does_match) {
        advance();
    }

    return does_match;
}

std::string ParserPack::advance_if_matches_or_throw(
    lex::TokenKind token_kind) {
    auto pre_increment_token_borrow = get_token();
    const auto got_token_kind =
        pre_increment_token_borrow.get_kind();

    if (got_token_kind == token_kind) {
        advance();

        core::Logger::log_info(std::format(
            "TokenKind {} matched", *token_kind));

        return pre_increment_token_borrow
            .move_out_lexeme();
    }

    throw exceptions::InvalidTokenException(
        get_pos(), token_kind, got_token_kind);
}

bool ParserPack::is_at_end() const {
    const auto is_finished =
        token_stream.size() <= progress;

    return is_finished;
}

[[nodiscard]] std::string
ParserPack::get_error_message() const {
    return std::format("invalid Token: '{}' at '{}'",
                       *get_kind(),
                       get_pos().to_string());
}
}  // namespace marex::parse
