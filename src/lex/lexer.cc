#include "lexer.h"

#include <absl/base/attributes.h>

#include <string>

#include "char_table.h"
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
        FlushStatement(result);
      default:
        last_word_.push_back(source_text_char);
        break;
    }
  }

  FlushStatement(result);

  return result;
}

void Lexer::FlushStatement(TokenStream& result) {
  result.EmplaceBack(
      token_factory_.CreateToken(std::string{last_word_}));

  last_word_.clear();
}
}  // namespace compiler::lex
