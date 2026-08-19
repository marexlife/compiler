#include "Node.h"
#include "IdentNode.h"
#include "Logger.h"
#include "PrintNode.h"
#include "Token.h"
#include "VarNode.h"
#include <string>
#include <utility>

namespace marex::parse {
Node::Node(lex::Token &&token) : token(std::move(token)) {}

std::string Node::asString() {
    switch (getKind()) {
    case marex::lex::TokenKind::Identifier:
        return cast<parse::IdentNode>().asString();
    case marex::lex::TokenKind::Print:
        return cast<parse::PrintNode>().asString();
    case marex::lex::TokenKind::Var:
        return cast<parse::VarNode>().asString();
    case marex::lex::TokenKind::None:
        [[fallthrough]];
    default:
        core::Logger::logFatalInternalError("not a valid Node");
    }
}
} // namespace marex::parse