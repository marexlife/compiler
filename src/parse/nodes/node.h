#ifndef COMPILER_PARSE_NODES_NODE_H_
#define COMPILER_PARSE_NODES_NODE_H_
namespace compiler::parse::nodes {
class Node {
 public:
  Node() = default;
  Node(Node&&) = default;
  Node& operator=(Node&&) = default;
  Node(const Node&) = delete;
  Node& operator=(const Node&) = delete;
  virtual ~Node() = default;
};
}  // namespace compiler::parse::nodes
#endif  // COMPILER_PARSE_NODES_NODE_H_
