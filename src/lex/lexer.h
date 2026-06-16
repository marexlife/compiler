#ifndef COMPILER_LEX_LEXER_H_
#define COMPILER_LEX_LEXER_H_
#include <absl/container/flat_hash_map.h>
#include <absl/strings/string_view.h>

#include <string>
#include <string_view>
#include <vector>

#include "token_kind.h"

namespace compiler::lex {
class Lexer final {
 public:
  Lexer() = default;
  Lexer(Lexer&&) = delete;
  Lexer& operator=(Lexer&&) = delete;
  Lexer(const Lexer&) = delete;
  Lexer& operator=(const Lexer&) = delete;
  ~Lexer() = default;

  [[nodiscard]] static std::vector<std::string> Run(
      std::basic_string_view<int> source_text);

 private:

};
}  // namespace compiler::lex
#endif  // COMPILER_LEXER_LEXER_H_