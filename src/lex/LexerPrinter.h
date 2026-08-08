#ifndef COMPILER_DEBUG_LEXPRINER_H
#define COMPILER_DEBUG_LEXPRINER_H
#include "TokenStream.h"

namespace compiler::lex {
class LexerPrinter final {
public:
    LexerPrinter() = delete;

    static void printLexerResult(lex::TokenStream& tokenStream);
};
} // namespace compiler::debug
#endif // COMPILER_DEBUG_LEXPRINER_H
