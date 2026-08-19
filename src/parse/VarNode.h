#ifndef MAREX_PARSE_VAR_NODE_H
#define MAREX_PARSE_VAR_NODE_H
#include "IdentNode.h"
#include "Node.h"
#include "Token.h"
#include <functional>
#include <optional>

namespace marex::parse {
class VarNode final : public Node {
  public:
    explicit VarNode(lex::Token &&token);

    void print();

    void setIdentNode(IdentNode &identNode) {
        this->identNode = identNode;
    }

  private:
    std::optional<std::reference_wrapper<IdentNode>> identNode =
        std::nullopt;
};
} // namespace marex::parse
#endif // MAREX_PARSE_VAR_NODE_H
