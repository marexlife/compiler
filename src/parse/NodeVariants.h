#ifndef MAREX_PARSE_NODEVARIANTS_H
#define MAREX_PARSE_NODEVARIANTS_H
#include "NodeKind.h"
#include <string>
#include <type_traits>

namespace marex::parse {
template <typename T>
concept IsNodeVariant =
    std::is_same_v<decltype(T::getNodeKind()), NodeKind>;

template <IsNodeVariant SubNode> class NodeVaraint {
  public:
    NodeVaraint(NodeVaraint &&) = default;
    ~NodeVaraint() = default;

    NodeVaraint &operator=(NodeVaraint &&) = delete;
    NodeVaraint(const NodeVaraint &) = delete;
    NodeVaraint &operator=(const NodeVaraint &) = delete;

  protected:
    NodeVaraint() = default;
};

template <IsNodeVariant ValueType> class ValueNode {
  public:
    ValueNode(ValueNode &&) = default;
    ~ValueNode() = default;

    ValueNode &operator=(ValueNode &&) = delete;
    ValueNode(const ValueNode &) = delete;
    ValueNode &operator=(const ValueNode &) = delete;

  protected:
    ValueNode() = default;

  private:
    std::string name;
};

class InvalidNode final : public NodeVaraint<InvalidNode> {
  public:
    [[nodiscard]] static consteval NodeKind getNodeKind() {
        return NodeKind::Var;
    }
};

class VarNode final : public NodeVaraint<VarNode> {
  public:
    [[nodiscard]] static consteval NodeKind getNodeKind() {
        return NodeKind::Var;
    }
};

class IndentNode final : public NodeVaraint<IndentNode> {
  public:
    [[nodiscard]] static consteval NodeKind getNodeKind() {
        return NodeKind::Var;
    }

  private:
};

class PrintNode final : public NodeVaraint<PrintNode> {
  public:
    [[nodiscard]] static consteval NodeKind getNodeKind() {
        return NodeKind::Var;
    }
};
} // namespace marex::parse
#endif // MAREX_PARSE_NODEVARIANTS_H