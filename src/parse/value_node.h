#ifndef COMPILER_PARSE_VALUENODE_H_
#define COMPILER_PARSE_VALUENODE_H_
#include <type_traits>
#include <utility>

#include "node.h"

namespace compiler::parse {
template <typename T>
  requires std::is_move_constructible_v<T> && std::is_default_constructible_v<T>
class ValueNode : public Node {
 public:
  explicit ValueNode(T&& value) : value_(std::move(value)) {}
  ValueNode(ValueNode&&) = default;
  ValueNode& operator=(ValueNode&&) = delete;
  ValueNode(const ValueNode&) = delete;
  ValueNode& operator=(const ValueNode&) = delete;
  ~ValueNode() override = default;

  [[nodiscard]] const T& value() const { return value_; }

 private:
  T value_{};
};
}  // namespace compiler::parse
#endif  // COMPILER_PARSE_VALUENODE_H_
