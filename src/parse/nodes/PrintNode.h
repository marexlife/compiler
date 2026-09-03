#ifndef MAREX_PARSE_PRINTNODE_H
#define MAREX_PARSE_PRINTNODE_H
#include <string>

#include "AstNode.h"
#include "IdentNode.h"
#include "ParserPack.h"
#include "Token.h"

namespace marex::parse {
class PrintNode final : public AstNode {
   public:
    explicit PrintNode(lex::Token&& token);

    [[nodiscard]] std::string as_string() override;

    void parse(ParserPack& pack) override;

   private:
    std::optional<std::reference_wrapper<IdentNode>>
        ident_node = std::nullopt;
};
}  // namespace marex::parse
#endif  // MAREX_PARSE_PRINTNODE_H
