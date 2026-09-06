#ifndef MAREX_PARSE_COMPLEXEXPRESSION_H
#define MAREX_PARSE_COMPLEXEXPRESSION_H
#include "nodes/AstNode.h"

namespace marex::parse {
class ComplexExpression final : public Parsable {
   public:
    [[nodiscard]] std::string as_c() override;

    void parse(ParserPack& pack) override;
};
}  // namespace marex::parse
#endif  // MAREX_PARSE_COMPLEXEXPRESSION_H