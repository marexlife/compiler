#include "Node.h"
#include "IdentNode.h"
#include "Logger.h"
#include "PrintNode.h"
#include "Token.h"
#include "VarNode.h"
#include <string>
#include <utility>

namespace marex::parse {
Node::Node(lex::Token &&token) : token(std::move(token)) {}

std::string Node::as_string() {
    switch (get_kind()) {
    case marex::lex::TokenKind::Identifier:
        return cast<parse::IdentNode>().as_string();
    case marex::lex::TokenKind::Print:
        return cast<parse::PrintNode>().as_string();
    case marex::lex::TokenKind::Var:
        return cast<parse::VarNode>().as_string();
    case marex::lex::TokenKind::None:
        [[fallthrough]];
    default:
        core::Logger::log_fatal_internal_error("not a valid Node");
    }
}

JumpCount Node::parse_node(Node &next_node) {
    switch (get_kind()) {
    case lex::TokenKind::Var:
        return cast<VarNode>().parse(next_node);
    case lex::TokenKind::Print:
        return cast<PrintNode>().parse(next_node);
    case lex::TokenKind::Identifier:
        return IdentNode::parse();
    case lex::TokenKind::None:
        [[fallthrough]];
    default:
        core::Logger::log_fatal_internal_error("invalid node kind");
    }
}
} // namespace marex::parse