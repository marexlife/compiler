#include "Expression.h"

#include <string>

#include "ParserPack.h"

namespace marex::parse {
std::string Expression::as_c() { return ""; }

void Expression::parse(
    [[maybe_unused]] ParserPack& pack) {}
}  // namespace marex::parse