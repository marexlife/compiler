#include "lex.h"

#include <cstddef>
#include <string>
#include <vector>

namespace compiler::lex {
[[nodiscard]] auto Lex(const std::string_view source_text)
    -> std::vector<std::string> {
  std::vector<std::string> result;
  {
    static const std::size_t kResultReserveAmount = 100;

    result.reserve(kResultReserveAmount);
  }

  for (const auto source_text_char : source_text) {
  }

  return result;
}
}  // namespace compiler::lex