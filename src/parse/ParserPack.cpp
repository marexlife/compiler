#include "ParserPack.h"

#include <format>

#include "TokenKind.h"
#include "TokenKindUitls.h"
#include "exceptions/InvalidTokenException.h"

namespace marex::parse {
std::string_view ParserPack::advance_if_matches(
    lex::TokenKind token_kind) {
    const auto& pre_increment_token_borrow =
        get_token();

    if (pre_increment_token_borrow.get_kind() ==
        token_kind) {
        advance();

        return pre_increment_token_borrow.get_lexeme();
    }

    throw exceptions::InvalidTokenException(
        get_pos(),
        std::format(
            "expected {}",
            lex::get_token_kind_name(token_kind)));
}
}  // namespace marex::parse