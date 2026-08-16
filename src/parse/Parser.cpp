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
        processStatement(statement);
    }
}

void Parser::processStatement(lex::Statement &statement) {
    std::vector<std::unique_ptr<Node>> nodes =
        transformToNodes(statement);

    processNodes(std::move(nodes));
}

void Parser::processNodes(std::vector<std::unique_ptr<Node>> nodes) {
    for (std::unique_ptr<Node> &node : nodes) {
        processNode(node);
    }
}

void Parser::processNode(
    [[maybe_unused]] std::unique_ptr<Node> &node) {}

std::vector<std::unique_ptr<Node>>
Parser::transformToNodes(lex::Statement &statement) {
    std::vector<std::unique_ptr<Node>> nodes{};

    for (auto &token : statement) {
        nodes.emplace_back(NodeFactory::createNode(token));
    }

    return nodes;
}
} // namespace marex::parse
