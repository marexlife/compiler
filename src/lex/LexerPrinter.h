#ifndef MAREX_DEBUG_LEXPRINER_H
#define MAREX_DEBUG_LEXPRINER_H
#include "TokenStream.h"

namespace marex::lex {
class LexerPrinter final {
public:
    LexerPrinter() = delete;

    static void print_lexer_result(
        lex::TokenStream& token_stream);
};
} // namespace marex::lex
#endif // MAREX_DEBUG_LEXPRINER_H
