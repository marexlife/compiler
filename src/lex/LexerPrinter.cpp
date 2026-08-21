#include "LexerPrinter.h"

#include "TokenStream.h"

namespace marex::lex {
void LexerPrinter::print_lexer_result(
    lex::TokenStream &token_stream) {
    for (lex::Statement &statement : token_stream) {
        std::cout << "Statement:\n";

        for (lex::Token &token : statement) {
            std::cout << "  Token: " << token.get_lexeme() << '\n';
        }
    }

    std::cout.flush();
}
} // namespace marex::lex
