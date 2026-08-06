#ifndef COMPILER_LEX_LASTCHARKIND_H_
#define COMPILER_LEX_LASTCHARKIND_H_
#include <cstdint>
enum class [[nodiscard]] LastCharKind : std::uint8_t {
  kNone,
  kWasDefault,
  kWasNotDefault,
};
#endif  // COMPILER_LEX_LASTCHARKIND_H_
