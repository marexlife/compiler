#ifndef COMPILER_PARSE_NODE_H_
#define COMPILER_PARSE_NODE_H_
namespace compiler::parse {
class Node {
 public:
  Node() noexcept = default;
  Node(Node&&) noexcept = default;
  Node& operator=(Node&&) = default;
  Node(const Node&) = delete;
  Node& operator=(const Node&) = delete;
  virtual ~Node() noexcept = default;
};
}  // namespace compiler::parse
#endif  // COMPILER_PARSE_NODE_H_
