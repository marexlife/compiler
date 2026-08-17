#include "NodeFactory.h"
#include "Logger.h"
#include "Node.h"
#include "PrintNode.h"
#include "TokenKind.h"
#include "VarNode.h"
#include <utility>

namespace marex::parse {
Node *NodeFactory::createNode(lex::Token &&token) {
    switch (token.getKind()) {
    case lex::TokenKind::Identifier:
        return new Node(std::move(token));
    case lex::TokenKind::Print:
        return new PrintNode(std::move(token));
    case lex::TokenKind::Var:
        return new VarNode(std::move(token));
    case lex::TokenKind::None:
        core::Logger::logFatalInternalError("token kind is none");
    default:
        core::Logger::logFatalInternalError("invalid token kind");
    }
}
} // namespace marex::parse