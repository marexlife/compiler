#ifndef COMPILER_PARSE_NODES_VAR_NODE_H_
#define COMPILER_PARSE_NODES_VAR_NODE_H_
#include "singal_node.h"

namespace compiler::parse::nodes {
class VarNode final : public SingalNode {
 public:
  VarNode() = default;
};
}  // namespace compiler::parse::nodes
#endif  // COMPILER_PARSE_NODES_VAR_NODE_H_
