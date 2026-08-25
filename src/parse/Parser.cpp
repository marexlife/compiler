#include "Parser.h"

#include "Node.h"
#include "NodeFactory.h"
#include "Statement.h"
#include "Token.h"
#include "TokenStream.h"
#include <cstddef>
#include <memory>
#include <sys/types.h>
#include <utility>
#include <vector>

namespace marex::parse {
void Parser::run([[maybe_unused]] lex::TokenStream &&token_stream) {}

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

void Parser::set_nodes(
    [[maybe_unused]] std::vector<std::unique_ptr<Node>> &nodes) {}
} // namespace marex::parse
