#ifndef COMPILER_PARSE_IDENTNODE_H_
#define COMPILER_PARSE_IDENTNODE_H_
#include <string>

#include "value_node.h"

namespace compiler::parse {
class IdentNode final : public ValueNode<std::string> {
  using Super = ValueNode<std::string>;

 public:
  explicit IdentNode(std::string&& value) : Super(std::move(value)) {}
  IdentNode(IdentNode&&) = default;
  IdentNode& operator=(IdentNode&&) = delete;
  IdentNode(const IdentNode&) = delete;
  IdentNode& operator=(const IdentNode&) = delete;
  ~IdentNode() override = default;

 private:
};
}  // namespace compiler::parse
#endif  // COMPILER_PARSE_IDENTNODE_H_
