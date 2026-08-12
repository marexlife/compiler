#ifndef MAREX_PARSE_NODE_H
#define MAREX_PARSE_NODE_H
#include "Logger.h"
#include "NodeKind.h"
#include "NodeStorage.h"
#include "NodeVariants.h"
#include "Token.h"
#include <concepts>
#include <functional>
#include <optional>
#include <utility>

namespace marex::parse {
class Node final {
  public:
    [[nodiscard]] static Node createNode(lex::Token &token);

    Node(Node &&) = default;
    Node &operator=(Node &&) = default;
    Node(const Node &) = delete;
    Node &operator=(const Node &) = delete;

    ~Node() {
        switch (nodeKind) {
        case NodeKind::Print:
            break;
        case NodeKind::Var:
            break;
        case NodeKind::None:
            core::Logger::logFatalInternalError("Node value is None");
            break;
        }

    fatal:
        core::Logger::logFatalInternalError("Invalid node value");
    }

    [[nodiscard]] NodeKind getNodeKind() const { return nodeKind; }

    template <IsNodeVariant T> [[nodiscard]] T &getTokenStorageAs() {
        return nodeStorage;
    }

    template <IsNodeVariant T>
    [[nodiscard]] const T &getTokenStorageAs() const {
        return nodeStorage;
    }

    void setLhs(std::optional<std::reference_wrapper<Node>> value) {
        lhs = value;
    }

    void setRhs(std::optional<std::reference_wrapper<Node>> value) {
        rhs = value;
    }

  private:
    template <IsNodeVariant T>
        requires std::move_constructible<T>
    explicit Node(T &&node, NodeKind nodeKind)
        : nodeStorage{std::move(node)} {}

    NoadeStorage nodeStorage;
    NodeKind nodeKind = NodeKind::None;

    std::optional<std::reference_wrapper<Node>> lhs = std::nullopt;
    std::optional<std::reference_wrapper<Node>> rhs = std::nullopt;
};
} // namespace marex::parse
#endif // MAREX_PARSE_NODE_H
