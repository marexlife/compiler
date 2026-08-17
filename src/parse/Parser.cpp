#include "Parser.h"

#include "Defer.h"
#include "Node.h"
#include "NodeFactory.h"
#include "Statement.h"
#include "Token.h"
#include "TokenStream.h"
#include <functional>
#include <optional>
#include <utility>

namespace marex::parse {
void Parser::run(lex::TokenStream &&tokenStream) {
    for (lex::Statement &statement : tokenStream) {
        Parser::processStatement(statement);
    }
}

void Parser::processStatement(lex::Statement &statement) {
    ct::VisitorVector<Node> nodes{};

    for (lex::Token &token : statement) {
        nodes.push(NodeFactory::createNode(std::move(token)));
    }

    Parser::processNodes(nodes);
}

void Parser::processNodes(ct::VisitorVector<Node> &nodes) {
    std::optional<std::reference_wrapper<Node>> perviusNodeOptional =
        std::nullopt;

    nodes.forEach([&](Node &node) -> void {
        core::Defer deferSetPerviousNode = [&]() -> void {
            perviusNodeOptional = node;
        };

        if (perviusNodeOptional == std::nullopt) {
            return;
        }

        Parser::processNode(*perviusNodeOptional, node);
    });
}

void Parser::processNode([[maybe_unused]] Node &previousNode,
                         [[maybe_unused]] Node &currentNode) {}
} // namespace marex::parse
