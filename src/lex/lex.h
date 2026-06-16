#ifndef COMPILER_LEX_LEX_H_
#define COMPILER_LEX_LEX_H_
#include <string>
#include <string_view>
#include <vector>

namespace compiler::lex {
[[nodiscard]] auto Lex(std::string_view source_text)
    -> std::vector<std::string>;
}
#endif  // COMPILER_LEXER_LEXER_H_