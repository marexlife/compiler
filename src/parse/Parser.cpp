#include "Parser.h"

#include "Node.h"
#include "NodeFactory.h"
#include "Statement.h"
#include "TokenStream.h"

namespace marex::parse {
void Parser::run(lex::TokenStream &&tokenStream) {
    for (lex::Statement &statement : tokenStream) {
        Parser::processStatement(statement);
    }
}

void Parser::processStatement(lex::Statement &statement) {
    ct::VisitorVector<Node> nodes{};

    for (auto &token : statement) {
        nodes.push(NodeFactory::createNode(token));
    }

    Parser::processNodes(nodes);
}

void Parser::processNodes(ct::VisitorVector<Node> &nodes) {
    nodes.forEach([](Node &node) { processNode(node); });
}

void Parser::processNode([[maybe_unused]] Node &node) {}
} // namespace marex::parse
