#include "lexer.h"

#include <absl/base/attributes.h>

#include <string>

#include "char_table.h"
#include "statement.h"
#include "token.h"
#include "token_stream.h"

namespace compiler::lex {
TokenStream Lexer::Run(std::string&& source_text) {
  TokenStream result;

  result.Reserve(kVectorDefaultSize);

  for (const auto source_text_char : source_text) {
    switch (source_text_char) {
      case CharTable::kNewLine:
        // ignore
        break;
      case CharTable::kSpace:
        PushToken();
      case CharTable::kSemicolon:
        PushStatement(result);
      default:
        last_word_.push_back(source_text_char);
        break;
    }
  }

  PushStatement(result);

  return result;
}

void Lexer::PushToken() {
  last_statement_.EmplaceBack(
      token_factory_.CreateToken(std::string{last_word_}));

  last_word_.clear();
}

void Lexer::PushStatement(TokenStream& result) {
  result.EmplaceBack(Statement{last_statement_});

  last_statement_.Clear();
}
}  // namespace compiler::lex
