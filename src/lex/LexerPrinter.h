#ifndef MAREX_DEBUG_LEXPRINER_H
#define MAREX_DEBUG_LEXPRINER_H
#include "TokenStream.h"

namespace marex::lex {
class LexerPrinter final {
  public:
    LexerPrinter() = delete;

    static void printLexerResult(lex::TokenStream &tokenStream);
};
} // namespace marex::lex
#endif // MAREX_DEBUG_LEXPRINER_H
