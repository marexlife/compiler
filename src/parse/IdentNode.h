#ifndef COMPILER_PARSE_IDENTNODE_H
#define COMPILER_PARSE_IDENTNODE_H
#include <string>

#include "ValueNode.h"

namespace compiler::parse {
using IdentNode = ValueNode<std::string, class IdentNodeTag>;
} // namespace compiler::parse
#endif // COMPILER_PARSE_IDENTNODE_H
