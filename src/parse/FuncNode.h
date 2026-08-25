#ifndef MAREX_PARSE_FUNCNODE_H
#define MAREX_PARSE_FUNCNODE_H
#include "Node.h"

namespace marex::parse {
class FuncNode final : public AstNode {
   public:
    [[nodiscard]] std::string as_string() override;

    void parse(ParserPack& pack) override;
};
}  // namespace marex::parse
#endif  // MAREX_PARSE_FUNCNODE_H