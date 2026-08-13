#include "Parser.h"

#include "Node.h"
#include "NodeFactory.h"
#include "Statement.h"
#include "TokenStream.h"
#include <memory>
#include <vector>

namespace marex::parse {
void Parser::run(lex::TokenStream &&tokenStream) {
    for (lex::Statement &statement : tokenStream) {
        Parser::processStatement(statement);
    }
}

void Parser::processStatement(lex::Statement &statement) {
    auto nodes = transformToNodes(statement);

    Parser::processNodes(std::move(nodes));
}

std::vector<std::shared_ptr<Node>>
Parser::transformToNodes(lex::Statement &statement) {
    std::vector<std::shared_ptr<Node>> nodes;

    std::ranges::transform(statement, nodes.begin(),
                           [&](lex::Token &token) {
                               return NodeFactory::createNode(token);
                           });

    return nodes;
}

void Parser::processNodes(
    std::vector<std::shared_ptr<Node>> &&nodes) {
    for (std::shared_ptr<Node> &node : nodes) {
        Parser::processNode(*node);
    }
}

void Parser::processNode([[maybe_unused]] Node &node) {}
} // namespace marex::parse
