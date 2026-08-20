#include "LexerPrinter.h"

#include "TokenStream.h"

namespace marex::lex {
void LexerPrinter::print_lexer_result(lex::TokenStream &tokenStream) {
    for (lex::Statement &statement : tokenStream) {
        std::cout << "Statement:\n";

        for (lex::Token &token : statement) {
            std::cout << "  Token: " << token.get_lexeme() << '\n';
        }
    }

    std::cout.flush();
}
} // namespace marex::lex
