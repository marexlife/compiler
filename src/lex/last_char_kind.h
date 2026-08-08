#ifndef COMPILER_LEX_LASTCHARKIND_H
#define COMPILER_LEX_LASTCHARKIND_H

#include <cstdint>

namespace compiler::lex 
{
enum class [[nodiscard]] LastCharKind : std::uint8_t 
{
  None,
  WasDefault,
  WasNotDefault,
};
}
#endif // COMPILER_LEX_LASTCHARKIND_H
