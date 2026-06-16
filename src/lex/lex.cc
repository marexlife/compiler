#include "lex.h"

#include <string>
#include <vector>

namespace compiler::lex {
[[nodiscard]] auto Lex(std::string_view source_text)
    -> std::vector<std::string> {
  std::vector<std::string> result;

  for (const auto source_text_char : source_text) {
  }

  return result;
}
}  // namespace compiler::lexer