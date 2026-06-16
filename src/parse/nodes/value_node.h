#ifndef COMPILER_PARSE_NODES_VALUENODE_H_
#define COMPILER_PARSE_NODES_VALUENODE_H_
#include <type_traits>
#include <utility>

#include "node.h"

namespace compiler::parse::nodes {
template <typename WrappedType, typename Tag = WrappedType>
  requires std::is_move_constructible_v<WrappedType> &&
           std::is_default_constructible_v<WrappedType>
class ValueNode : public Node {
 public:
  explicit ValueNode(WrappedType&& value) : value_(std::move(value)) {}
  ValueNode(ValueNode&&) = default;
  ValueNode& operator=(ValueNode&&) = delete;
  ValueNode(const ValueNode&) = delete;
  ValueNode& operator=(const ValueNode&) = delete;
  ~ValueNode() override = default;

  [[nodiscard]] const WrappedType& value() const { return value_; }

 private:
  WrappedType value_{};
};
}  // namespace compiler::parse::nodes
#endif  // COMPILER_PARSE_NODES_VALUENODE_H_
