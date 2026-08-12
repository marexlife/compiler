#ifndef MAREX_PARSE_NODE_H
#define MAREX_PARSE_NODE_H
#include "Logger.h"
#include "Token.h"
#include <concepts>
#include <cstdint>
#include <functional>
#include <optional>
#include <source_location>
#include <utility>

namespace marex::parse {
class VarNode final {};
class PrintNode final {};

enum class [[nodiscard]] NodeKind : std::uint8_t {
    None = 0,

};

union TokenStorage final {};

class Node final {
  public:
    [[nodiscard]] static Node createNode(lex::Token &token);

    Node(Node &&) = default;
    Node &operator=(Node &&) = default;
    Node(const Node &) = delete;
    Node &operator=(const Node &) = delete;
    ~Node() {
        switch (nodeKind) {

        case NodeKind::None:
            goto fatal;
            break;
        }

    fatal:
        core::Logger::logFatalInternalError("invalid node value!",
                                            std::source_location{});
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
    template <typename T>
        requires std::move_constructible<T>
    explicit Node(T &&node, TokenStorage tokenStorage)
        : tokenStorage{std::move(node)} {}

    TokenStorage tokenStorage;
    NodeKind nodeKind = NodeKind::None;

    std::optional<std::reference_wrapper<Node>> lhs = std::nullopt;
    std::optional<std::reference_wrapper<Node>> rhs = std::nullopt;
};
} // namespace marex::parse
#endif // MAREX_PARSE_NODE_H
