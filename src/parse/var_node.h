#ifndef COMPILER_PARSE_VAR_NODE_H_
#define COMPILER_PARSE_VAR_NODE_H_
#include "singal_node.h"

namespace compiler::parse {
class VarNode final : public SingalNode {
 public:
  VarNode() = default;
};
}  // namespace compiler::parse
#endif  // COMPILER_PARSE_VAR_NODE_H_
