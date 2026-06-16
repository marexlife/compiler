#include "lex.h"

#include <cstddef>
#include <string>
#include <vector>

#include "detail/char_table.h"

namespace compiler::lex {
[[nodiscard]] auto Lex(const std::string_view source_text)
    -> std::vector<std::string> {
  std::vector<std::string> result;
  {
    static const std::size_t kResultReserveAmount = 100;

    result.reserve(kResultReserveAmount);
  }

  for (const auto source_text_char : source_text) {
    switch (source_text_char) {
      case detail::CharTable::kSpace:
        [[fallthrough]];
      case detail::CharTable::kNewLine:
        
        break;
      default:
        break;
    }
  }

  return result;
}
}  // namespace compiler::lex