#include "Parser.h"

#include "Defer.h"
#include "IdentNode.h"
#include "JumpCont.h"
#include "Logger.h"
#include "Node.h"
#include "NodeFactory.h"
#include "PrintNode.h"
#include "Statement.h"
#include "Token.h"
#include "TokenKind.h"
#include "TokenStream.h"
#include "VarNode.h"
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

    Parser::parse_nodes(nodes);

    return nodes;
}

void Parser::parse_nodes(std::vector<std::unique_ptr<Node>> &nodes) {
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

        forward_jump_count =
            Parser::parse_node(*pervious_node_optional, *node);
    }
}

JumpCount Parser::parse_node(Node &self, Node &next_node) {
    switch (self.get_kind()) {
    case lex::TokenKind::Var:
        return Parser::try_parse_var(self.cast<VarNode>(), next_node);
    case lex::TokenKind::Print:
        return Parser::try_parse_print(self.cast<PrintNode>(),
                                       next_node);
    case lex::TokenKind::Identifier:
        core::Logger::log_fatal_error("identifier not valid here");
        break;
    case lex::TokenKind::None:
        [[fallthrough]];
    default:
        core::Logger::log_fatal_internal_error("invalid node kind");
        break;
    }

    return 0;
}

JumpCount Parser::try_parse_var(VarNode &self, Node &ident_node) {
    switch (ident_node.get_kind()) {
    case lex::TokenKind::Identifier:
        return Parser::parse_var(self, ident_node.cast<IdentNode>());
    default:
        core::Logger::log_fatal_error(
            "wrong thing after var. try: var x");
    }
}

JumpCount Parser::parse_var(VarNode &self, IdentNode &ident_node) {
    self.set_ident_node(ident_node);

    return 2;
}

JumpCount Parser::try_parse_print(PrintNode &self, Node &ident_node) {
    switch (self.get_kind()) {
    case lex::TokenKind::Identifier:
        return Parser::parse_print(self,
                                   ident_node.cast<IdentNode>());
    default:
        core::Logger::log_fatal_error(
            "wrong thing after var. try: print hey");
    }
}

JumpCount Parser::parse_print(PrintNode &self,
                              IdentNode &target_node) {
    self.set_target_node(target_node);

    return 2;
}
} // namespace marex::parse
