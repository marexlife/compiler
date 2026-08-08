#include "node_factory.h"

#include <exception>

#include "ident_node.h"
#include "print_node.h"
#include "var_node.h"

namespace compiler::parse 
{
std::unique_ptr<Node> NodeFactory::newNode(lex::Token& input) 
{
    switch (input.kind()) {
    case lex::TokenKind::Identifier:
        return std::make_unique<IdentNode>(input.lexeme());
    case lex::TokenKind::Print:
        return std::make_unique<PrintNode>();
    case lex::TokenKind::Var:
        return std::make_unique<VarNode>();
    default:
        std::terminate();
    }
}
}  // namespace compiler::parse
