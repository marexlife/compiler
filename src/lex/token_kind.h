#ifndef COMPILER_LEX_TOKENKIND_H_
#define COMPILER_LEX_TOKENKIND_H_
#include <cstdint>

namespace compiler::lex {
enum class TokenKind : std::uint8_t {
  kNone = 0,
  kIdentifier,
};
}
#endif  // COMPILER_LEX_TOKENKIND_H_