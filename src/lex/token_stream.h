#ifndef COMPILER_LEX_TOKENSTREAM_H
#define COMPILER_LEX_TOKENSTREAM_H
#include <vector>

#include "statement.h"

namespace compiler::lex {
using TokenStream = std::vector<Statement>;
} // namespace compiler::lex
#endif // COMPILER_LEX_TOKENSTREAM_H
