#ifndef COMPILER_LEX_TOKENKIND_H
#define COMPILER_LEX_TOKENKIND_H
#include <cstdint>

namespace compiler::lex 
{
enum class [[nodiscard]] TokenKind : std::uint8_t 
{
  None = 0,
  Identifier,
  Print,
  Var,
};
}
#endif  // COMPILER_LEX_TOKENKIND_H
