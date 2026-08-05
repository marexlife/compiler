#ifndef COMPILER_PARSE_NODEFACTORY_H_
#define COMPILER_PARSE_NODEFACTORY_H_
#include <memory>

#include "node.h"
#include "token.h"

namespace compiler::parse {
class NodeFactory final {
 public:
  NodeFactory() = delete;

  [[nodiscard]] static std::unique_ptr<Node> NewNode(
      lex::Token& input);
};
}  // namespace compiler::parse
#endif  // COMPILER_PARSE_NODEFACTORY_H_
