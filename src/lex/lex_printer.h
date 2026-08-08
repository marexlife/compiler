#ifndef COMPILER_DEBUG_LEXPRINER_H
#define COMPILER_DEBUG_LEXPRINER_H
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
#endif  // COMPILER_DEBUG_LEXPRINER_H
