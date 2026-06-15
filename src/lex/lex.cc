#include "lex.h"

#include <string>
#include <vector>

namespace compiler::lex {
[[nodiscard]] std::vector<std::string> Lex(std::string_view source_text) {
  std::vector<std::string> result;

  for (const auto source_text_char : source_text) {
  }

  return result;
}
}  // namespace compiler::lexer