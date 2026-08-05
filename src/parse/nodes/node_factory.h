#ifndef COMPILER_PARSE_NODES_NODE_FACTORY_H_
#define COMPILER_PARSE_NODES_NODE_FACTORY_H_
#include <memory>

#include "node.h"
#include "token.h"

namespace compiler::parse::nodes {
class NodeFactory final {
 public:
  NodeFactory() = delete;

  [[nodiscard]] static std::unique_ptr<nodes::Node> TransformToNode(
      lex::Token& input);
};
}  // namespace compiler::parse::nodes
#endif  // COMPILER_PARSE_NODES_NODE_FACTORY_H_
