#include "Parser.h"

#include "Node.h"
#include "Statement.h"
#include "TokenStream.h"
#include <vector>

namespace marex::parse {
void Parser::run(lex::TokenStream &&tokenStream) {
    for (lex::Statement &statement : tokenStream) {
        Parser::processStatement(statement);
    }
}

void Parser::processStatement(lex::Statement &statement) {
    std::vector<Node> nodes = transformToNodes(statement);

    Parser::processNodes(std::move(nodes));
}

std::vector<Node>
Parser::transformToNodes(lex::Statement &statement) {
    std::vector<Node> nodes;

    std::ranges::transform(statement, nodes.begin(),
                           [&](lex::Token &token) -> Node {
                               return Node::createNode(token);
                           });

    return nodes;
}

void Parser::processNodes(std::vector<Node> &&nodes) {
    for (parse::Node &node : nodes) {
        Parser::processNode(node);
    }
}

void Parser::processNode(Node &node) {}
} // namespace marex::parse
