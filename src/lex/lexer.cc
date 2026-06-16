#include "lexer.h"

#include <cstddef>
#include <string>
#include <vector>

#include "detail/char_table.h"

namespace compiler::lex {
std::vector<std::string> Lexer::Lex(const std::string_view source_text) {
  std::vector<std::string> result{};
  {
    static const std::size_t kResultReserveAmount{100};

    result.reserve(kResultReserveAmount);
  }

  for (const auto sourceTextChar : source_text) {
    switch (sourceTextChar) {
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