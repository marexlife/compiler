#include "LexerPrinter.h"

#include <format>
#include <iostream>

#include "Logger.h"
#include "Token.h"
#include "TokenStream.h"

namespace marex::lex {
void LexerPrinter::print_token_stream(
    lex::TokenStream& token_stream) {
    core::Logger::log_info("\nLexer print start\n");

    for (lex::Token& token : token_stream) {
        core::Logger::log_info(std::format(
            "Token: {}\n", token.get_lexeme()));
    }

    core::Logger::log_info("Lexer print end\n\n");

    core::Logger::flush();
}
}  // namespace marex::lex
