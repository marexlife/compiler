#include "Node.h"
#include "Token.h"

namespace marex::parse {
[[nodiscard]] Node Node::createNode(lex::Token &token) {
    switch (token.getKind()) {
    case lex::TokenKind::Identifier:
        return Node{IndentNode{}, NodeKind::Print};
    case lex::TokenKind::Print:
        return Node{PrintNode{}, NodeKind::Print};
    case lex::TokenKind::Var:
        return Node{VarNode{}, NodeKind::Var};
    case lex::TokenKind::None:
        core::Logger::logFatalInternalError("Enum value is None");
        break;
    default:
        core::Logger::logFatalInternalError("Invalid enum value");
        break;
    }
}
} // namespace marex::parse