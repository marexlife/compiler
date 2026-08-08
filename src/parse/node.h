#ifndef COMPILER_PARSE_NODE_H
#define COMPILER_PARSE_NODE_H
namespace compiler::parse
{
class Node 
{
  public:
	Node() = default;
	Node(Node&&) = default;
	Node& operator=(Node&&) = default;
	Node(const Node&) = delete;
	Node& operator=(const Node&) = delete;
	virtual ~Node() = default;
};
}  // namespace compiler::parse
#endif  // COMPILER_PARSE_NODE_H
