#include "NodeFactory.h"
#include "Logger.h"
#include "Node.h"
#include "PrintNode.h"
#include "TokenKind.h"
#include "VarNode.h"
#include <memory>
#include <utility>

namespace marex::parse {
std::unique_ptr<Node> NodeFactory::createNode(lex::Token &&token) {
    switch (token.getKind()) {
    case lex::TokenKind::Identifier:
        return std::make_unique<Node>(std::move(token));
    case lex::TokenKind::Print:
        return std::make_unique<PrintNode>(std::move(token));
    case lex::TokenKind::Var:
        return std::make_unique<VarNode>(std::move(token));
    case lex::TokenKind::None:
        core::Logger::logFatalInternalError("token kind is none");
    default:
        core::Logger::logFatalInternalError("invalid token kind");
    }
}
} // namespace marex::parse