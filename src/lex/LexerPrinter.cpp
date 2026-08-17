#include "LexerPrinter.h"

#include "TokenStream.h"

namespace marex::lex {
void LexerPrinter::printLexerResult(lex::TokenStream &tokenStream) {
    for (lex::Statement &statement : tokenStream) {
        std::cout << "Statement:\n";

        for (lex::Token &token : statement) {
            std::cout << "  Token: " << token.GetLexeme() << '\n';
        }
    }

    std::cout << '\n';
}
} // namespace marex::lex
