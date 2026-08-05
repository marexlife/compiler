#include "token_factory.h"

#include <absl/strings/string_view.h>

#include <string_view>

#include "passkey.h"
#include "token.h"
#include "token_kind.h"

namespace compiler::lex {
Token TokenFactory::CreateToken(std::string&& source_word) {
  return Token{
      core::Passkey<TokenFactory>{},
      std::move(source_word),
      Map(source_word),
  };
}

[[nodiscard]] TokenKind TokenFactory::Map(
    std::string_view source_word) {
  if (mapping_.contains(source_word)) {
    return mapping_.at(source_word);
  } else {
    return TokenKind::Identifier;
  }
}
}  // namespace compiler::lex
