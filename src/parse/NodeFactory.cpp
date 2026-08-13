#include "NodeFactory.h"
#include "Logger.h"
#include "Node.h"
#include "PrintNode.h"
#include "TokenKind.h"
#include "VarNode.h"
#include <memory>

namespace marex::parse {
std::shared_ptr<Node> NodeFactory::createNode(lex::Token &token) {
    switch (token.getKind()) {
    case marex::lex::TokenKind::Identifier:
        return std::make_unique<Node>();
    case marex::lex::TokenKind::Print:
        return std::make_unique<PrintNode>();
    case marex::lex::TokenKind::Var:
        return std::make_unique<VarNode>();
    case marex::lex::TokenKind::None:
        marex::core::Logger::logFatalInternalError(
            "token kind is none");
    default:
        marex::core::Logger::logFatalInternalError(
            "invalid token kind");
    }
}
} // namespace marex::parse