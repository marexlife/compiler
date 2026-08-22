#include "Parser.h"

#include "Defer.h"
#include "Node.h"
#include "NodeFactory.h"
#include "Statement.h"
#include "Token.h"
#include "TokenStream.h"
#include <cstddef>
#include <functional>
#include <memory>
#include <optional>
#include <utility>
#include <vector>

namespace marex::parse {
std::vector<std::vector<std::unique_ptr<Node>>>
Parser::run(lex::TokenStream &&token_stream) {
    std::vector<std::vector<std::unique_ptr<Node>>> list_of_nodes;

    for (lex::Statement &statement : token_stream) {
        auto process_result = Parser::process_statement(statement);

        list_of_nodes.emplace_back(std::move(process_result));
    }

    return list_of_nodes;
}

std::vector<std::unique_ptr<Node>>
Parser::process_statement(lex::Statement &statement) {
    std::vector<std::unique_ptr<Node>> nodes{};

    for (lex::Token &token : statement) {
        nodes.emplace_back(
            NodeFactory::create_node(std::move(token)));
    }

    Parser::set_nodes(nodes);

    return nodes;
}

void Parser::set_nodes(std::vector<std::unique_ptr<Node>> &nodes) {
    std::size_t progress = 1;

    while (progress < nodes.size()) {
        auto &previous_node = *nodes.at(progress - 1);
        auto &current_node = *nodes.at(progress);

        progress += previous_node.set(current_node);
    }
}
} // namespace marex::parse
