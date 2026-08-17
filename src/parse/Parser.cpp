#include "Parser.h"

#include "Node.h"
#include "NodeFactory.h"
#include "Statement.h"
#include "TokenStream.h"
#include <utility>

namespace marex::parse {
void Parser::run(lex::TokenStream &&tokenStream) {
    for (lex::Statement &statement : tokenStream) {
        Parser::processStatement(statement);
    }
}

void Parser::processStatement(lex::Statement &statement) {
    ct::VisitorVector<Node> nodes{};

    for (auto &token : statement) {
        nodes.push(NodeFactory::createNode(std::move(token)));
    }

    Parser::processNodes(nodes);
}

void Parser::processNodes(ct::VisitorVector<Node> &nodes) {
    nodes.forEach([](Node &node) { Parser::processNode(node); });
}

void Parser::processNode([[maybe_unused]] Node &node) {}
} // namespace marex::parse
