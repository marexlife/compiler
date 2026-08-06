#include "lexer.h"

#include <absl/base/attributes.h>

#include <iostream>
#include <optional>
#include <string>

#include "absl/status/status.h"
#include "statement.h"
#include "token.h"
#include "token_stream.h"

namespace compiler::lex {
absl::StatusOr<TokenStream> Lexer::Run(std::string&& source_text) {
  TokenStream result;

  result.reserve(kVectorDefaultSize);

  std::optional<char> last_char_optional = std::nullopt;
  bool is_first_time = true;

  for (const auto source_text_char : source_text) {
    switch (source_text_char) {
      case '\n':
        [[fallthrough]];
      case '\0':
        // ignore
        break;
      case ' ':
        if (!last_char_optional.has_value()) {
          PushToken();
        }
        break;
      case ';':
        PushStatement(result);
        break;
      default:
        std::cout << "Default\n";
        last_word_.push_back(source_text_char);
        break;
    }

    is_first_time = false;
    last_char_optional = source_text_char;
  }

  if (!last_char_optional.has_value()) [[unlikely]] {
    return absl::AbortedError("Lexer: Empty.");
  }

  if (*last_char_optional != ';') [[unlikely]] {
    return absl::AbortedError("The last has to be a ';'.");
  }

  return result;
}

void Lexer::PushToken() {
  std::cout << "PushToken\n";
  last_statement_.emplace_back(
      token_factory_.CreateToken(std::string{last_word_}));

  last_word_.clear();
}

void Lexer::PushStatement(TokenStream& result) {
  PushToken();

  std::cout << "Push Statement\n";

  result.push_back(Statement{last_statement_});

  last_statement_.clear();
}
}  // namespace compiler::lex
