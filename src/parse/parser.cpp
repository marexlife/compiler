#include "parser.h"

#include <exception>

#include "token.h"
#include "token_kind.h"
#include "token_stream.h"

namespace compiler::parse {
void Parser::run(lex::TokenStream&& tokenStream) {
    Node result{};
  
    for (auto& statement : tokenStream) {
        processStatement(statement);
    }
}

void Parser::processStatement(lex::Statement& statement) {  
    for (auto& token : statement) {
        processToken(token);
    }
}

void Parser::processToken(lex::Token& token) 
{
    switch (token.kind()) {
    case lex::TokenKind::Identifier:
        break;
    default:
        break;
    }
}
}  // namespace compiler::parse
