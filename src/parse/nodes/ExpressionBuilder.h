#ifndef MAREX_PARSE_EXPRESSIONBUILDER_H
#define MAREX_PARSE_EXPRESSIONBUILDER_H
#include "ParserPack.h"

namespace marex::parse {
class ExpressionBuilder final {
   public:
    static void build(ParserPack& pack);
};
}  // namespace marex::parse
#endif  // MAREX_PARSE_EXPRESSIONBUILDER_H