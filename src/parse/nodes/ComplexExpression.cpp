#include "ComplexExpression.h"

#include <string>

#include "ParserPack.h"

namespace marex::parse {
std::string ComplexExpression::as_c() { return ""; }

void ComplexExpression::parse(
    [[maybe_unused]] ParserPack& pack) {}
}  // namespace marex::parse