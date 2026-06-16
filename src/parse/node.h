#ifndef COMPILER_PARSE_NODE_H_
#define COMPILER_PARSE_NODE_H_
namespace compiler::parse {
class Node final {
 public:
  Node() = default;
  Node(Node&&) = delete;
  Node& operator=(Node&&) = delete;
  Node(const Node&) = delete;
  Node& operator=(const Node&) = delete;
  ~Node() = default;

 private:
};
}  // namespace compiler::parse
#endif  // COMPILER_PARSE_NODE_H_
