#include "LexerPrinter.h"

#include <format>

#include "Logging.h"
#include "Token.h"
#include "TokenStream.h"

namespace marex::lex {
void LexerPrinter::print_token_stream(
    lex::TokenStream& token_stream) {
    core::log_info("\nLexer print start\n");

    for (lex::Token& token : token_stream) {
        core::log_info(std::format(
            "Token lexeme: '{}', Token kind: '{}'\n",
            *token.get_kind(), token.get_lexeme()));
    }

    core::log_info("Lexer print end\n\n");

    core::flush();
}
}  // namespace marex::lex
