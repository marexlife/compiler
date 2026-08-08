#ifndef COMPILER_NODES_OPNODE_H
#define COMPILER_NODES_OPNODE_H
#include "node.h"

namespace compiler::parse 
{
class OpNode final : public Node 
{
  public:
	OpNode() = default;

  private:
};
}  // namespace compiler::parse
#endif  // COMPILER_NODES_OPNODE_H
