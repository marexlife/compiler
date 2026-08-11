#ifndef MAREX_PARSE_IDENTNODE_H
#define MAREX_PARSE_IDENTNODE_H
#include <string>

#include "ValueNode.h"

namespace marex::parse {
using IdentNode = ValueNode<std::string, class IdentNodeTag>;
} // namespace compiler::parse
#endif // MAREX_PARSE_IDENTNODE_H
