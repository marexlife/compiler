#include "lexer.h"

#include <absl/base/attributes.h>

#include <optional>
#include <string>

#include "absl/status/status.h"
#include "defer.h"
#include "statement.h"
#include "token.h"
#include "token_stream.h"

namespace compiler::lex {
absl::StatusOr<TokenStream> Lexer::Run(std::string&& source_text) {
  TokenStream result;

  core::Defer defer_reset{[&]() { Reset(); }};

  result.reserve(kVectorDefaultSize);

  std::optional<char> last_char_optional = std::nullopt;
  bool last_char_was_default = true;

  for (const auto source_text_char : source_text) {
    bool this_char_was_default = false;

    core::Defer defer_iter_end{[&]() {
      last_char_optional = source_text_char;
      last_char_was_default = this_char_was_default;
    }};

    switch (source_text_char) {
      case '\n':
        [[fallthrough]];
      case '\0':
        // ignore
        break;
      case ' ':
        if (last_char_was_default) {
          PushToken();
        }

        break;
      case ';':
        PushStatement(result);
        break;
      default:
        this_char_was_default = true;
        last_word_.push_back(source_text_char);
        break;
    }
  }

  if (!last_char_optional.has_value()) [[unlikely]] {
    return absl::AbortedError("Lexer: Empty.");
  }

  if (*last_char_optional != ';') [[unlikely]] {
    return absl::AbortedError("The last has to be a ';'.");
  }

  return result;
}

void Lexer::Reset() {
  last_statement_.clear();
  last_word_.clear();
}

void Lexer::PushToken() {
  last_statement_.emplace_back(
      token_factory_.CreateToken(std::string{last_word_}));

  last_word_.clear();
}

void Lexer::PushStatement(TokenStream& result) {
  PushToken();

  result.push_back(Statement{last_statement_});

  last_statement_.clear();
}
}  // namespace compiler::lex
