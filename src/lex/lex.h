#ifndef COMPILER_LEX_LEX_H_
#define COMPILER_LEX_LEX_H_
#include <string>
#include <string_view>
#include <vector>

namespace compiler::lex {
[[nodiscard]] std::vector<std::string> Lex(std::string_view source_text);
}
#endif  // COMPILER_LEXER_LEXER_H_