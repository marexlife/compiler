#include "lex_printer.h"

#include <spdlog/spdlog.h>

#include "token_stream.h"

namespace compiler::lex {
void LexPrinter::PrintLexerResult(lex::TokenStream& token_stream) {
  for (lex::Statement statement : token_stream) {
    std::cout << "Statement:\n";

    for (lex::Token& token : statement) {
      std::cout << "  Token: {}" << token.lexeme() << '\n';
    }
  }

  std::cout << '\n';
}
}  // namespace compiler::lex
