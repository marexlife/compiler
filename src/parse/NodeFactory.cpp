#include "NodeFactory.h"

#include <format>
#include <memory>
#include <utility>

#include "IdentNode.h"
#include "Logger.h"
#include "AstNode.h"
#include "PrintNode.h"
#include "TokenKind.h"
#include "TokenKindUitls.h"
#include "VarNode.h"

namespace marex::parse {
std::unique_ptr<AstNode> NodeFactory::create_node(
    lex::Token&& token)
{
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
                lex::get_token_kind_name(token_kind)));
    }
}
} // namespace marex::parse