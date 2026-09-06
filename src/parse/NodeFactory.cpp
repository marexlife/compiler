#include "NodeFactory.h"

#include <format>
#include <memory>
#include <utility>

#include "Logging.h"
#include "TokenKind.h"
#include "nodes/IdentNode.h"
#include "nodes/VarNode.h"

namespace marex::parse {
std::unique_ptr<AstNode> NodeFactory::create_node(
    lex::Token&& token) {
    auto token_kind = token.get_kind();

    switch (token_kind) {
        case lex::TokenKind::Identifier:
            return std::make_unique<IdentNode>(
                std::move(token));
        case lex::TokenKind::Var:
            return std::make_unique<VarNode>(
                std::move(token));
        default:
            core::log_fatal_internal_error(
                std::format("invalid token kind '{}'",
                            *token_kind));
    }
}
}  // namespace marex::parse