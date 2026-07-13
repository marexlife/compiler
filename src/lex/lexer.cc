#include "lexer.h"

#include <absl/base/attributes.h>

#include <string>
#include <vector>

#include "detail/char_table.h"
#include "token.h"

namespace compiler::lex {
std::vector<Token> Lexer::Run(std::string&& source_text) {
  std::vector<Token> result;

  result.reserve(kVectorDefaultSize);

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

void Lexer::Flush(std::vector<Token>& result) {
  result.push_back(
      token_factory_.CreateToken(std::string{last_word_}));

  last_word_.clear();
}
}  // namespace compiler::lex
