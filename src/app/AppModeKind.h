#ifndef MAREX_APP_APPMODEKIND_H
#define MAREX_APP_APPMODEKIND_H
#include <cstdint>

namespace marex::app {
enum class [[nodiscard]] AppModeKind : std::uint8_t {
    Undecided,
    ShellMode,
    FileMode,
};
}
#endif // MAREX_APP_APPMODEKIND_H
