#include "lexer.h"

#include <absl/base/attributes.h>

#include <string>

#include "detail/char_table.h"
#include "token.h"

namespace compiler::lex {
absl::InlinedVector<Token, Lexer::kVectorDefaultSize> Lexer::Run(
    std::string&& source_text) {
  absl::InlinedVector<Token, kVectorDefaultSize> result{};

  for (const auto source_text_char : source_text) {
    switch (source_text_char) {
      case detail::CharTable::kSpace:
        [[fallthrough]];
      case detail::CharTable::kNewLine: {
        Flush(result);
      } break;
      default: {
        last_word_.push_back(source_text_char);
        break;
      }
    }
  }

  Flush(result);

  return result;
}

void Lexer::Flush(absl::InlinedVector<Token, kVectorDefaultSize>& result) {
  result.push_back(token_factory_.CreateToken(std::string{last_word_}));

  last_word_.clear();
}
}  // namespace compiler::lex
