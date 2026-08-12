#ifndef MAREX_PARSE_NODEDISPATCHER_H
#define MAREX_PARSE_NODEDISPATCHER_H
#include "NodeKind.h"
#include "NodeStorage.h"
#include "NodeVariants.h"
#include "Token.h"
#include <concepts>
#include <functional>
#include <optional>
#include <utility>

namespace marex::parse {
class NodeDispatcher final {
  public:
    [[nodiscard]] static NodeDispatcher createNode(lex::Token &token);

    NodeDispatcher(NodeDispatcher &&) = default;
    NodeDispatcher &operator=(NodeDispatcher &&) = default;

    NodeDispatcher(const NodeDispatcher &) = default;
    NodeDispatcher &operator=(const NodeDispatcher &) = default;

    ~NodeDispatcher();

    [[nodiscard]] NodeKind getNodeKind() const { return nodeKind; }

    template <IsNodeVariant T> [[nodiscard]] T &getTokenStorageAs() {
        return nodeStorage;
    }

    template <IsNodeVariant T>
    [[nodiscard]] const T &getTokenStorageAs() const {
        return nodeStorage;
    }

    void setLhs(std::reference_wrapper<NodeDispatcher> value) {
        lhs = value;
    }

    void setRhs(std::reference_wrapper<NodeDispatcher> value) {
        rhs = value;
    }

  private:
    template <IsNodeVariant NodeVariant>
        requires std::move_constructible<NodeVariant>
    explicit NodeDispatcher(NodeVariant &&node, NodeKind nodeKind)
        : nodeStorage(std::move(node)), nodeKind{nodeKind} {}

    NoadeStorage nodeStorage =
        NoadeStorage{.invalidNode = InvalidNode{}};
    NodeKind nodeKind = NodeKind::None;

    std::optional<std::reference_wrapper<NodeDispatcher>> lhs =
        std::nullopt;
    std::optional<std::reference_wrapper<NodeDispatcher>> rhs =
        std::nullopt;
};
} // namespace marex::parse
#endif // MAREX_PARSE_NODEDISPATCHER_H
