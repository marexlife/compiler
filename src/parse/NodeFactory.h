#ifndef MAREX_PARSE_NODEFACTORY_H
#define MAREX_PARSE_NODEFACTORY_H
#include "Node.h"
#include "Token.h"
#include <memory>

namespace marex::parse {
class NodeFactory final {
  public:
    [[nodiscard]] static std::shared_ptr<Node>
    createNode(lex::Token &token);

  private:
};
} // namespace marex::parse
#endif // MAREX_PARSE_NODEFACTORY_H