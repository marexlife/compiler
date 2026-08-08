#include "Parser.h"

#include "Node.h"
#include "Token.h"
#include "TokenKind.h"
#include "TokenStream.h"

namespace compiler::parse {
void Parser::run(lex::TokenStream&& tokenStream)
{
    Node result { };

    for (auto& statement : tokenStream) {
        processStatement(statement);
    }
}

void Parser::processStatement(lex::Statement& statement)
{
    for (auto& token : statement) {
        processToken(token);
    }
}

void Parser::processToken(lex::Token& token)
{
    switch (token.getKind()) {
    case lex::TokenKind::Identifier:
        break;
    default:
        break;
    }
}
} // namespace compiler::parse
