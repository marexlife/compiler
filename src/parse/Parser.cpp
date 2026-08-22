#include "Parser.h"

#include "Defer.h"
#include "JumpCont.h"
#include "Node.h"
#include "NodeFactory.h"
#include "Statement.h"
#include "Token.h"
#include "TokenStream.h"
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
    std::optional<std::reference_wrapper<Node>>
        pervious_node_optional = std::nullopt;
    JumpCount forward_jump_count = 0;

    for (std::unique_ptr<Node> &node : nodes) {
        core::Defer iter_defer = [&]() {
            pervious_node_optional = *node;

            if (forward_jump_count > 0) {
                --forward_jump_count;
            }
        };

        if (pervious_node_optional == std::nullopt ||
            forward_jump_count != 0) {
            continue;
        }

        forward_jump_count = pervious_node_optional->get().set(*node);
    }
}
} // namespace marex::parse
