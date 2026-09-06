#include "StatementBuilder.h"

#include <vector>

#include "ParserPack.h"
#include "nodes/Expression.h"

namespace marex::parse {
void StatementBuilder::build(
    [[maybe_unused]] ParserPack& pack) {
    std::vector<Expression> expression_range;
}
}  // namespace marex::parse