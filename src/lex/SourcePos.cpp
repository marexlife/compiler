#include "SourcePos.h"

#include <format>

namespace marex::lex {
void SourcePos::advance_column() { ++column; }

void SourcePos::advance_line() {
    ++line;
    column = {};
}

[[nodiscard]] std::string SourcePos::to_string()
    const {
    return std::format("{}:{}", line, column);
}
}  // namespace marex::lex