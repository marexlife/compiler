#include "lex_printer.h"

#include <spdlog/spdlog.h>

#include "token_stream.h"

namespace compiler::lex {
void LexPrinter::PrintLexerResult(lex::TokenStream& token_stream) {
  for (lex::Statement statement : token_stream) {
    spdlog::info("Statement: ");

    for (lex::Token& token : statement) {
      spdlog::info(std::format("Token: {}", token.lexeme()));
    }
  }

  std::cout << '\n';
}
}  // namespace compiler::lex
