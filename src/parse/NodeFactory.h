#ifndef MAREX_PARSE_NODEFACTORY_H
#define MAREX_PARSE_NODEFACTORY_H
#include <memory>

#include "Token.h"
#include "nodes/Parsable.h"

namespace marex::parse {
class NodeFactory final {
   public:
    [[nodiscard]] static std::unique_ptr<AstNode>
    create_node(lex::Token&& token);

   private:
};
}  // namespace marex::parse
#endif  // MAREX_PARSE_NODEFACTORY_H