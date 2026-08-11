#ifndef MAREX_LEX_LASTCHARKIND_H
#define MAREX_LEX_LASTCHARKIND_H

#include <cstdint>

namespace marex::lex {
enum class [[nodiscard]] LastCharKind : std::uint8_t {
    None,
    WasDefault,
    WasNotDefault,
};
}
#endif // MAREX_LEX_LASTCHARKIND_H
