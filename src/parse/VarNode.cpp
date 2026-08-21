#include "VarNode.h"
#include "Logger.h"
#include <format>
#include <string>
#include <utility>

namespace marex::parse {
VarNode::VarNode(lex::Token &&token) : Node(std::move(token)) {}

std::string VarNode::as_string() {
    if (ident_node) [[likely]] {
        return std::format("variable {}",
                           ident_node->get().as_string());
    }

    core::Logger::log_fatal_internal_error("no value for VarNode");
}

JumpCount VarNode::try_parse(Node &ident_node) {
    switch (ident_node.get_kind()) {
    case lex::TokenKind::Identifier:
        return parse(ident_node.cast<IdentNode>());
    default:
        core::Logger::log_fatal_error(
            "wrong thing after var. try: var x");
    }
}

JumpCount VarNode::parse(IdentNode &ident_node) {
    set_ident_node(ident_node);

    return 2;
}
} // namespace marex::parse