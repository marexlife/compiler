#include "InvalidTokenException.h"

#include <format>
#include <utility>

#include "TokenKindUitls.h"

namespace marex::parse::exceptions {
InvalidTokenException::InvalidTokenException(
    lex::SourcePos source_pos,
    lex::TokenKind expected_token_kind,
    lex::TokenKind got_token_kind)
    : full_message(std::format(
          "Invalid token: at {}\nexpected: {}, got {}",
          source_pos.to_string(),
          lex::get_token_kind_name(
              expected_token_kind),
          lex::get_token_kind_name(got_token_kind))) {}

InvalidTokenException::InvalidTokenException(
    std::string&& full_message)
    : full_message(
          std::format("Invalid token: {}",
                      std::move(full_message))) {}

const char* InvalidTokenException::what()
    const noexcept {
    return full_message.data();
}
}  // namespace marex::parse::exceptions
