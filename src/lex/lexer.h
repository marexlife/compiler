#ifndef COMPILER_LEX_LEXER_H_
#define COMPILER_LEX_LEXER_H_
#include <absl/container/inlined_vector.h>
#include <absl/strings/string_view.h>

#include <cstddef>
#include <string>

#include "token_factory.h"

namespace compiler::lex {
class [[nodiscard]] Lexer final {
  static constexpr std::size_t kVectorDefaultSize{10};

 public:
  Lexer() = default;
  Lexer(Lexer&&) = delete;
  Lexer& operator=(Lexer&&) = delete;
  Lexer(const Lexer&) = delete;
  Lexer& operator=(const Lexer&) = delete;
  ~Lexer() = default;

  [[nodiscard]] std::vector<Token> Run(std::string&& source_text);

 private:
  void Flush(std::vector<Token>& result);

  TokenFactory token_factory_{};
  std::string last_word_{};
};
}  // namespace compiler::lex
#endif  // COMPILER_LEXER_LEXER_H_
