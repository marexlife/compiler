#ifndef MAREX_PARSE_STATEMENTBUILDER_H
#define MAREX_PARSE_STATEMENTBUILDER_H
#include "ParserPack.h"

namespace marex::parse {
class StatementBuilder final {
   public:
    static void build(ParserPack& pack);
};
}  // namespace marex::parse
#endif  // MAREX_PARSE_STATEMENTBUILDER_H