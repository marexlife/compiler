#ifndef COMPILER_DEBUG_LEXPRINER_H_
#define COMPILER_DEBUG_LEXPRINER_H_
#include "token_stream.h"

namespace compiler::lex 
{
class LexPrinter final 
{
 public:
  LexPrinter() = delete;

  static void printLexerResult(lex::TokenStream& tokenStream);
};
}  // namespace compiler::debug
#endif  // COMPILER_DEBUG_LEXPRINER_H_
