#include "LexerPrinter.h"

#include <iostream>

#include "Token.h"
#include "TokenStream.h"

namespace marex::lex {
void LexerPrinter::print_token_stream(
    lex::TokenStream& token_stream) {
    std::cout << "\nLexer print start\n";
    for (lex::Token& token : token_stream) {
        std::cout << "  Token: " << token.get_lexeme()
                  << '\n';
    }

    std::cout << "Lexer print end\n\n";
    std::cout.flush();
}
}  // namespace marex::lex
