#ifndef COMPILER_PARSE_IDENTNODE_H_
#define COMPILER_PARSE_IDENTNODE_H_
#include <string>

#include "value_node.h"

namespace compiler::parse {
using IdentNode = ValueNode<std::string, class IdentNodeTag>;
}  // namespace compiler::parse
#endif  // COMPILER_PARSE_IDENTNODE_H_
