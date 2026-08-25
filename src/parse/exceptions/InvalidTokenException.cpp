#include "InvalidTokenException.h"

#include <format>

#include "TokenKindUitls.h"

namespace marex::parse::exceptions {
InvalidTokenException::InvalidTokenException(
    lex::SourcePos source_pos,
    lex::TokenKind expected_token_kind)
    : full_message(
          std::format("at {}\nexpected: {}",
                      source_pos.to_string(),
                      lex::get_token_kind_name(
                          expected_token_kind))) {}

const char* InvalidTokenException::what()
    const noexcept {
    return full_message.data();
}
}  // namespace marex::parse::exceptions