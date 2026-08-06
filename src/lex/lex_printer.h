#ifndef COMPILER_DEBUG_LEXPRINER_H_
#define COMPILER_DEBUG_LEXPRINER_H_
#include "token_stream.h"

namespace compiler::lex {
class LexPrinter final {
 public:
  LexPrinter() = delete;

  static void PrintLexerResult(lex::TokenStream& token_stream);
};
}  // namespace compiler::debug
#endif  // COMPILER_DEBUG_LEXPRINER_H_
