#include "NodeFactory.h"
#include "Logger.h"
#include "Node.h"
#include "PrintNode.h"
#include "TokenKind.h"
#include "VarNode.h"
#include <memory>

namespace marex::parse {
std::unique_ptr<Node> NodeFactory::createNode(lex::Token &token) {
    switch (token.getKind()) {
    case marex::lex::TokenKind::Identifier:
        return std::make_unique<Node>();
    case marex::lex::TokenKind::Print:
        return std::make_unique<PrintNode>();
    case marex::lex::TokenKind::Var:
        return std::make_unique<VarNode>();
    default:
        marex::core::Logger::logFatalInternalError(
            "invalid node value");
    }
}
} // namespace marex::parse