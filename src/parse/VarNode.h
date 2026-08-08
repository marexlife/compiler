#ifndef COMPILER_PARSE_VAR_NODE_H
#define COMPILER_PARSE_VAR_NODE_H
#include "SingalNode.h"

namespace compiler::parse {
class VarNode final : public SingalNode {
public:
    VarNode() = default;
};
} // namespace compiler::parse
#endif // COMPILER_PARSE_VAR_NODE_H
