#ifndef COMPILER_PARSE_NODES_OPNODE_H_
#define COMPILER_PARSE_NODES_OPNODE_H_
#include "node.h"

namespace compiler::parse::nodes {
class OpNode final : public Node {
 public:
  OpNode() = default;
  OpNode(OpNode&&) = default;
  OpNode& operator=(OpNode&&) = delete;
  OpNode(const OpNode&) = delete;
  OpNode& operator=(const OpNode&) = delete;
  ~OpNode() override = default;

 private:
};
}  // namespace compiler::parse::nodes
#endif  // COMPILER_PARSE_NODES_OPNODE_H_