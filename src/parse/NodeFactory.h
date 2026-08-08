#ifndef COMPILER_PARSE_NODEFACTORY_H
#define COMPILER_PARSE_NODEFACTORY_H
#include <memory>

#include "Node.h"
#include "Token.h"

namespace compiler::parse {
class NodeFactory final {
public:
    NodeFactory() = delete;

    [[nodiscard]] static std::unique_ptr<Node> newNode(
        lex::Token& input);
};
} // namespace compiler::parse
#endif // COMPILER_PARSE_NODEFACTORY_H
