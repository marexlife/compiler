#include "PrintNode.h"
#include "IdentNode.h"
#include "Logger.h"
#include <format>
#include <utility>

namespace marex::parse {
PrintNode::PrintNode(lex::Token &&token) : Node(std::move(token)) {}

std::string PrintNode::as_string() {
    if (ident_node) [[likely]] {
        return std::format("print {}", ident_node->get().as_string());
    }

    core::Logger::log_fatal_internal_error("no value for print node");
}

JumpCount PrintNode::try_parse_print(Node &ident_node) {
    switch (get_kind()) {
    case lex::TokenKind::Identifier:
        return parse_print(ident_node.cast<IdentNode>());
    default:
        core::Logger::log_fatal_error(
            "wrong thing after var. try: print hey");
    }
}

JumpCount PrintNode::parse_print(IdentNode &target_node) {
    set_target_node(target_node);

    return 2;
}
} // namespace marex::parse