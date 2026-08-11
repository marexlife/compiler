#ifndef MAREX_PARSE_OPNODEKIND_H
#define MAREX_PARSE_OPNODEKIND_H
#include <cstdint>

namespace marex::parse {
enum class [[nodiscard]] OpNodeKind : std::uint8_t {
    None = 0,
    Plus,
    Minus,
    Multiply,
    Divide,
};
}
#endif // MAREX_PARSE_OPNODEKIND_H
