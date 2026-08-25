#include "LexerPrinter.h"

#include "Token.h"
#include "TokenStream.h"

namespace marex::lex {
void LexerPrinter::print_lexer_result(
    lex::TokenStream& token_stream)
{
    for (lex::Token& token : token_stream) {
        std::cout << "  Token: " << token.get_lexeme()
                  << '\n';
    }

    std::cout.flush();
}
} // namespace marex::lex
