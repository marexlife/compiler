#ifndef MAREX_PARSE_PRINTNODE_H
#define MAREX_PARSE_PRINTNODE_H
#include "IdentNode.h"
#include "JumpCont.h"
#include "Node.h"
#include "Token.h"
#include <string>

namespace marex::parse {
class PrintNode final : public Node {
  public:
    explicit PrintNode(lex::Token &&token);

    [[nodiscard]] std::string as_string();

    void set_target_node(IdentNode &targetNode) {
        ident_node = targetNode;
    }

    [[nodiscard]] JumpCount try_parse(Node &ident_node);

    [[nodiscard]] JumpCount parse(IdentNode &target_node);

  private:
    std::optional<std::reference_wrapper<IdentNode>> ident_node =
        std::nullopt;
};
} // namespace marex::parse
#endif // MAREX_PARSE_PRINTNODE_H
