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
          lex::token_kind_to_string(
              expected_token_kind),
          lex::token_kind_to_string(got_token_kind))) {
}

InvalidTokenException::InvalidTokenException(
    lex::SourcePos source_pos,
    lex::TokenKind unexpected_token_kind)
    : full_message(std::format(
          "at: {}, unexpected token kind: {}",
          source_pos.to_string(),
          lex::token_kind_to_string(
              unexpected_token_kind))) {}

InvalidTokenException::InvalidTokenException(
    lex::SourcePos source_pos,
    std::string&& full_message)
    : full_message(
          std::format("at {}\nInvalid token: {}",
                      source_pos.to_string(),
                      std::move(full_message))) {}

const char* InvalidTokenException::what()
    const noexcept {
    return full_message.data();
}
}  // namespace marex::parse::exceptions
