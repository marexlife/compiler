#include "lex_printer.h"

#include <spdlog/spdlog.h>

#include "token_stream.h"

namespace compiler::lex {
void LexPrinter::printLexerResult(lex::TokenStream& tokenStream)
{
    for (lex::Statement statement : tokenStream) {
        std::cout << "Statement:\n";

        for (lex::Token& token : statement) {
            std::cout << "  Token: " << token.getLexeme() << '\n';
        }
    }

    std::cout << '\n';
}
} // namespace compiler::lex
