#include "NodeFactory.h"

#include <exception>

#include "IdentNode.h"
#include "PrintNode.h"
#include "VarNode.h"

namespace marex::parse {
std::unique_ptr<Node> NodeFactory::newNode(lex::Token &input) {
    switch (input.getKind()) {
    case lex::TokenKind::Identifier:
        return std::make_unique<IdentNode>(input.getLexeme());
    case lex::TokenKind::Print:
        return std::make_unique<PrintNode>();
    case lex::TokenKind::Var:
        return std::make_unique<VarNode>();
    default:
        std::terminate();
    }
}
} // namespace compiler::parse
