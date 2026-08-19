#include "Node.h"
#include "IdentNode.h"
#include "Logger.h"
#include "PrintNode.h"
#include "Token.h"
#include "VarNode.h"
#include <utility>

namespace marex::parse {
Node::Node(lex::Token &&token) : token(std::move(token)) {}

void Node::print() {
    switch (getKind()) {
    case marex::lex::TokenKind::Identifier:
        cast<parse::IdentNode>().print();
        break;
    case marex::lex::TokenKind::Print:
        cast<parse::PrintNode>().print();
        break;
    case marex::lex::TokenKind::Var:
        cast<parse::VarNode>().print();
        break;
    case marex::lex::TokenKind::None:
        [[fallthrough]];
    default:
        core::Logger::logFatalInternalError("not a valid Node");
    }
}
} // namespace marex::parse