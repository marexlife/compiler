#ifndef MAREX_PARSE_NODEFACTORY_H
#define MAREX_PARSE_NODEFACTORY_H
#include <memory>

#include "Node.h"
#include "Token.h"

namespace marex::parse {
class NodeFactory final {
  public:
    NodeFactory() = delete;

    [[nodiscard]] static std::unique_ptr<Node>
    newNode(lex::Token &input);
};
} // namespace compiler::parse
#endif // MAREX_PARSE_NODEFACTORY_H
