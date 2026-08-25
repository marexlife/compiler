#include "TokenPos.h"

namespace marex::lex {
void TokenPos::advance_column() { ++column; }

void TokenPos::advance_line() {
    ++line;
    column = {};
}
} // namespace marex::lex