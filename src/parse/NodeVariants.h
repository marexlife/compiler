#ifndef MAREX_PARSE_NODEVARIANTS_H
#define MAREX_PARSE_NODEVARIANTS_H
#include "NodeKind.h"
#include <type_traits>

namespace marex::parse {
template <typename T>
concept IsNodeVariant =
    std::is_same_v<decltype(T::getNodeKind()), NodeKind>;

struct VarNode final {
    [[nodiscard]] static NodeKind getNodeKind() {
        return NodeKind::Var;
    }
};

struct IndentNode final {
    [[nodiscard]] static NodeKind getNodeKind() {
        return NodeKind::Var;
    }
};

struct PrintNode final {
    [[nodiscard]] static NodeKind getNodeKind() {
        return NodeKind::Var;
    }
};
} // namespace marex::parse
#endif // MAREX_PARSE_NODEVARIANTS_H