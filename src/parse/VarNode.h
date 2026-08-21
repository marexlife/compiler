#ifndef MAREX_PARSE_VAR_NODE_H
#define MAREX_PARSE_VAR_NODE_H
#include "IdentNode.h"
#include "JumpCont.h"
#include "Node.h"
#include "Token.h"
#include <functional>
#include <optional>
#include <string>

namespace marex::parse {
class VarNode final : public Node {
  public:
    explicit VarNode(lex::Token &&token);

    [[nodiscard]] std::string as_string();

    [[nodiscard]] JumpCount parse(Node &ident_node);

  private:
    std::optional<std::reference_wrapper<IdentNode>> ident_node =
        std::nullopt;
};
} // namespace marex::parse
#endif // MAREX_PARSE_VAR_NODE_H
