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
    std::vector<std::unique_ptr<Node>> nodes =
        transformToNodes(statement);

    Parser::processNodes(std::move(nodes));
}

std::vector<std::unique_ptr<Node>>
Parser::transformToNodes(lex::Statement &statement) {
    std::vector<std::unique_ptr<Node>> nodes{};

    for (auto &token : statement) {
        nodes.emplace_back(NodeFactory::createNode(token));
    }

    return nodes;
}

void Parser::processNodes(std::vector<std::unique_ptr<Node>> nodes) {
    for (std::unique_ptr<Node> &node : nodes) {
        Parser::processNode(node);
    }
}

void Parser::processNode(
    [[maybe_unused]] std::unique_ptr<Node> &node) {}
} // namespace marex::parse
