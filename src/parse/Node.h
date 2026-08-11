#ifndef MAREX_PARSE_NODE_H
#define MAREX_PARSE_NODE_H
#include "Logger.h"
#include <concepts>
#include <cstdint>
#include <utility>

namespace marex::parse {
enum class [[nodiscard]] NodeKind : std::uint8_t {
    None = 0,

};

union TokenStorage final {};

class VarNode final {};
class PrintNode final {};

class Node final {
  public:
    template <typename T>
        requires std::move_constructible<T>
    explicit Node(T &&node, TokenStorage tokenStorage)
        : tokenStorage{std::move(node)} {}

    Node(Node &&) = default;
    Node &operator=(Node &&) = default;
    Node(const Node &) = delete;
    Node &operator=(const Node &) = delete;
    ~Node() {
        switch (nodeKind) {
        case NodeKind::None:
            core::Logger::logFatalInternalError("none is selected!");
            break;
        }
    }

    [[nodiscard]] NodeKind getNodeKind() const { return nodeKind; }

    template <typename T> [[nodiscard]] T &getTokenStorageAs() {
        return tokenStorage;
    }
    template <typename T>
    [[nodiscard]] const T &getTokenStorageAs() const {
        return tokenStorage;
    }

  private:
    TokenStorage tokenStorage;
    NodeKind nodeKind = NodeKind::None;
};
} // namespace marex::parse
#endif // MAREX_PARSE_NODE_H
