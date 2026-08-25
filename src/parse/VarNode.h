#ifndef MAREX_PARSE_VAR_NODE_H
#define MAREX_PARSE_VAR_NODE_H
#include "IdentNode.h"
#include "Node.h"
#include "ParserPack.h"
#include "Token.h"
#include <functional>
#include <optional>
#include <string>

namespace marex::parse {
class VarNode final : public AstNode {
  public:
    explicit VarNode(lex::Token &&token);

    [[nodiscard]] std::string as_string() override;

    void parse(ParserPack &pack) override;

  private:
    std::optional<std::reference_wrapper<IdentNode>> ident_node =
        std::nullopt;
};
} // namespace marex::parse
#endif // MAREX_PARSE_VAR_NODE_H
