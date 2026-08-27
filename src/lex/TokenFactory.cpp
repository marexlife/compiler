#include "TokenFactory.h"

#include <absl/strings/string_view.h>

#include <string_view>

#include "Passkey.h"
#include "SourcePos.h"
#include "Token.h"
#include "TokenKind.h"

namespace marex::lex {
TokenFactory::TokenFactory()
    : mapping{
          {
              {"print", TokenKind::Print},
              {"var", TokenKind::Var},
              {"class", TokenKind::Class},
              {"fun", TokenKind::Func},
              {":", TokenKind::Colon},
              {"=", TokenKind::Assignment},
              {";", TokenKind::StatementEnd},
              {"\n", TokenKind::StatementEnd},
              {"struct", TokenKind::Struct},
              {"{", TokenKind::OpenBrace},
              {"}", TokenKind::CloseBrace},
              {"(", TokenKind::OpenBracket},
              {")", TokenKind::CloseBracket},
          },
      } {}

Token TokenFactory::create_token(
    std::string&& source_word, SourcePos source_pos) {
    return Token{
        core::Passkey<TokenFactory>{},
        std::move(source_word),
        map(source_word),
        source_pos,
    };
}

[[nodiscard]] TokenKind TokenFactory::map(
    std::string_view source_word) {
    if (mapping.contains(source_word)) {
        return mapping.at(source_word);
    }

    return TokenKind::Identifier;
}
}  // namespace marex::lex
