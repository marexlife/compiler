#include "SourcePos.h"

namespace marex::lex {
void SourcePos::advance_column() { ++column; }

void SourcePos::advance_line() {
    ++line;
    column = {};
}
}  // namespace marex::lex