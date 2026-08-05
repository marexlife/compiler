#include "node_factory.h"

#include "ident_node.h"
#include "print_node.h"
#include "var_node.h"

namespace compiler::parse {
std::unique_ptr<Node> NodeFactory::NewNode(lex::Token& input) {
  switch (input.token_kind()) {
    case lex::TokenKind::kIdentifier:
      return std::make_unique<IdentNode>(input.lexeme());
    case lex::TokenKind::kPrint:
      return std::make_unique<PrintNode>();
    case lex::TokenKind::kVar:
      return std::make_unique<VarNode>();
    default:
      std::unreachable();
  }
}
}  // namespace compiler::parse
