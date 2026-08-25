#include "NodeFactory.h"

#include <memory>
#include <utility>

#include "IdentNode.h"
#include "Logger.h"
#include "Node.h"
#include "PrintNode.h"
#include "TokenKind.h"
#include "VarNode.h"

namespace marex::parse {
std::unique_ptr<AstNode> NodeFactory::create_node(
    lex::Token&& token) {
    switch (token.get_kind()) {
        case lex::TokenKind::Ident:
            return std::make_unique<IdentNode>(
                std::move(token));
        case lex::TokenKind::Print:
            return std::make_unique<PrintNode>(
                std::move(token));
        case lex::TokenKind::Var:
            return std::make_unique<VarNode>(
                std::move(token));
        case lex::TokenKind::None:
            core::Logger::log_fatal_internal_error(
                "token kind is none");
        default:
            core::Logger::log_fatal_internal_error(
                "invalid token kind");
    }
}
}  // namespace marex::parse