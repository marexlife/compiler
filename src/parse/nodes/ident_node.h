#ifndef COMPILER_PARSE_NODES_IDENTNODE_H_
#define COMPILER_PARSE_NODES_IDENTNODE_H_
#include <string>

#include "value_node.h"

namespace compiler::parse::nodes {
using IdentNode = ValueNode<std::string, class IdentNodeTag>;
}  // namespace compiler::parse::nodes
#endif  // COMPILER_PARSE_NODES_IDENTNODE_H_
