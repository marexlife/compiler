#ifndef COMPILER_LEX_STATEMENT_H
#define COMPILER_LEX_STATEMENT_H
#include <vector>

#include "token.h"

namespace compiler::lex {
using Statement = std::vector<Token>;
} // namespace compiler::lex
#endif // COMPILER_LEX_STATEMENT_H
