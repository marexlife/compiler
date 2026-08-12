#include "Node.h"
#include "Token.h"

namespace marex::parse {
[[nodiscard]] Node Node::createNode(lex::Token &token) {
    switch (token.getKind()) {
    case lex::TokenKind::Identifier:

        break;
    case lex::TokenKind::Print:
        return Node{PrintNode{}, NodeKind::Print};
        break;
    case lex::TokenKind::Var:
        return Node{VarNode{}, NodeKind::Var};
    case lex::TokenKind::None:
        core::Logger::logFatalInternalError("Enum value is None");
    }

fail:
    core::Logger::logFatalInternalError("Invalid enum value");
}
} // namespace marex::parse