#include "Parser.h"

#include "NodeDispatcher.h"
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
    std::vector<NodeDispatcher> nodes = transformToNodes(statement);

    Parser::processNodes(std::move(nodes));
}

std::vector<NodeDispatcher>
Parser::transformToNodes(lex::Statement &statement) {
    std::vector<NodeDispatcher> nodes;

    std::ranges::transform(statement, nodes.begin(),
                           [&](lex::Token &token) -> NodeDispatcher {
                               return NodeDispatcher::createNode(
                                   token);
                           });

    return nodes;
}

void Parser::processNodes(std::vector<NodeDispatcher> &&nodes) {
    for (parse::NodeDispatcher &node : nodes) {
        Parser::processNode(node);
    }
}

void Parser::processNode([[maybe_unused]] NodeDispatcher &node) {}
} // namespace marex::parse
