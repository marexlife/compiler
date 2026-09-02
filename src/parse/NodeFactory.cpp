#include "NodeFactory.h"

#include <format>
#include <memory>
#include <utility>

#include "AstNode.h"
#include "IdentNode.h"
#include "Logger.h"
#include "PrintNode.h"
#include "TokenKind.h"
#include "TokenKindUitls.h"
#include "VarNode.h"

namespace marex::parse {
std::unique_ptr<AstNode> NodeFactory::create_node(
    lex::Token&& token) {
    auto token_kind = token.get_kind();

    switch (token_kind) {
        case lex::TokenKind::Identifier:
            return std::make_unique<IdentNode>(
                std::move(token));
        case lex::TokenKind::Print:
            return std::make_unique<PrintNode>(
                std::move(token));
        case lex::TokenKind::Var:
            return std::make_unique<VarNode>(
                std::move(token));
        default:
            core::Logger::log_fatal_internal_error(
                std::format("invalid token kind '{}'",
                            lex::token_kind_to_string(
                                token_kind)));
    }
}
}  // namespace marex::parse