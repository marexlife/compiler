#ifndef MAREX_PARSE_FUNCNODE_H
#define MAREX_PARSE_FUNCNODE_H
#include "Node.h"
#include "Token.h"

namespace marex::parse {
class FuncNode final : public AstNode {
   public:
    explicit FuncNode(lex::Token&& token);

    [[nodiscard]] std::string as_string() override;

    void parse(ParserPack& pack) override;
};
}  // namespace marex::parse
#endif  // MAREX_PARSE_FUNCNODE_H