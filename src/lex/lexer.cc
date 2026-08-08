#include "lexer.h"

#include <absl/base/attributes.h>

#include <optional>
#include <string>

#include "absl/status/status.h"
#include "defer.h"
#include "last_char_kind.h"
#include "statement.h"
#include "token.h"
#include "token_stream.h"

namespace compiler::lex {
absl::StatusOr<TokenStream> Lexer::Run(std::string&& source_text) 
{
    TokenStream result;

    core::Defer defer_reset{[&]() { Reset(); }};

    result.reserve(kVectorDefaultSize);

    std::optional<char> lastCharOptional = std::nullopt;
    LastCharKind lastCharKind = LastCharKind::kNone;

    for (const auto sourceTextChar : source_text) {
        LastCharKind thisCharKind = LastCharKind::kWasNotDefault;

        core::Defer defeIterEnd{[&]() {
            lastCharOptional = sourceTextChar;
            lastCharKind = thisCharKind;
        }};

        switch (sourceTextChar) {
          case '\n':
            [[fallthrough]];
          case '\0':
            // ignore
            break;
          case ' ':
            if (lastCharKind == LastCharKind::kWasDefault) {
              PushToken();
            }
            break;
          case ';':
            PushStatement(result);
            break;
          default:
            thisCharKind = LastCharKind::kWasDefault;
            last_word_.push_back(sourceTextChar);
            break;
        }
  }

  if (!lastCharOptional.has_value()) [[unlikely]] {
    return absl::AbortedError("Lexer: Empty.");
  }

  if (*lastCharOptional != ';') [[unlikely]] {
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
