#ifndef COMPILER_PARSE_IDENTNODE_H_
#define COMPILER_PARSE_IDENTNODE_H_
#include "node.h"

namespace compiler::parse {
class IdentNode final : public Node {
 public:
  IdentNode() = default;
  IdentNode(IdentNode&&) = default;
  IdentNode& operator=(IdentNode&&) = delete;
  IdentNode(const IdentNode&) = delete;
  IdentNode& operator=(const IdentNode&) = delete;
  ~IdentNode() override = default;

 private:
};
}  // namespace compiler::parse
#endif  // COMPILER_PARSE_IDENTNODE_H_
