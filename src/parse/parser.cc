#include "parser.h"

#include <exception>

#include "token.h"
#include "token_kind.h"
#include "token_stream.h"

namespace compiler::parse {
void Parser::Run(lex::TokenStream&& token_stream) {
  Node result{};
  
  for (auto& statement : token_stream) {
    ProcessStatement(statement);
  }
}

void Parser::ProcessStatement(lex::Statement& statement) {  
  for (auto& token : statement) {
    ProcessToken(token);
  }
}

void Parser::ProcessToken(lex::Token& token) {
  switch (token.kind()) {
    case lex::TokenKind::Identifier:
      break;
    default:
      break;
  }
}
}  // namespace compiler::parse
