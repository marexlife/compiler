#ifndef MAREX_PARSE_PRINTNODE_H
#define MAREX_PARSE_PRINTNODE_H
#include "IdentNode.h"
#include "Node.h"
#include "Token.h"

namespace marex::parse {
class PrintNode final : public Node {
  public:
    explicit PrintNode(lex::Token &&token);

    void print();

    void setTargetNode(IdentNode &targetNode) {
        identNode = targetNode;
    }

  private:
    std::optional<std::reference_wrapper<IdentNode>> identNode =
        std::nullopt;
};
} // namespace marex::parse
#endif // MAREX_PARSE_PRINTNODE_H
