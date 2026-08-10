#include "Parser.h"

#include "Node.h"
#include "Statement.h"
#include "Token.h"
#include "TokenKind.h"
#include "TokenStream.h"
#include <cstdint>

namespace compiler::parse {
void Parser::run(lex::TokenStream &&tokenStream) {
    Node result{};

    for (lex::Statement &statement : tokenStream) {
        Parser::processStatement(statement);
    }
}

void Parser::processStatement(lex::Statement &statement) {
    for (auto &token : statement) {
        std::uint8_t bindingPower = token.getBindingPower();

        Parser::processToken(token);
    }
}

void Parser::processToken(lex::Token &token) {
    switch (token.getKind()) {
    case lex::TokenKind::Identifier:
        break;
    default:
        break;
    }
}
} // namespace compiler::parse
