#include "NodeDispatcher.h"
#include "Token.h"

namespace marex::parse {
[[nodiscard]] NodeDispatcher
NodeDispatcher::createNode(lex::Token &token) {
    switch (token.getKind()) {
    case lex::TokenKind::Identifier:
        return NodeDispatcher{IndentNode{}, NodeKind::Print};
    case lex::TokenKind::Print:
        return NodeDispatcher{PrintNode{}, NodeKind::Print};
    case lex::TokenKind::Var:
        return NodeDispatcher{VarNode{}, NodeKind::Var};
    case lex::TokenKind::None:
        core::Logger::logFatalInternalError("Enum value is None");
        break;
    default:
        core::Logger::logFatalInternalError("Invalid enum value");
        break;
    }
}

NodeDispatcher::~NodeDispatcher() {
    switch (nodeKind) {
    case NodeKind::Print:
        break;
    case NodeKind::Var:
        break;
    case NodeKind::None:
        core::Logger::logFatalInternalError("Node value is None");
        break;
    default:
        core::Logger::logFatalInternalError("Invalid node value");
        break;
    }
}
} // namespace marex::parse