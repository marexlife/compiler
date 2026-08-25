#include "ParserPack.h"

namespace marex::parse {
[[nodiscard]] absl::StatusOr<std::string_view>
ParserPack::advance_if_matches(lex::TokenKind token_kind) {
    const auto &pre_increment_token_borrow = get_token();

    if (pre_increment_token_borrow.get_kind() == token_kind) {
        advance();

        return pre_increment_token_borrow.get_lexeme();
    }

    return absl::InternalError("Unwanted token kind");
}
} // namespace marex::parse