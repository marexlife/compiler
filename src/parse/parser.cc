#include "parser.h"

#include <algorithm>
#include <memory>
#include <utility>

#include "absl/container/inlined_vector.h"
#include "nodes/ident_node.h"
#include "nodes/if_node.h"
#include "nodes/print_node.h"
#include "nodes/var_node.h"
#include "token.h"
#include "token_kind.h"

namespace compiler::parse {
void Parser::Run() {}

absl::InlinedVector<std::unique_ptr<nodes::Node>,
                    Parser::kNodesDefaultReserve>
Parser::TransformToNodeVector(
    absl::InlinedVector<lex::Token, kNodesDefaultReserve>&& input) {
  absl::InlinedVector<std::unique_ptr<nodes::Node>,
                      kNodesDefaultReserve>
      result{};

  return result;
}

std::unique_ptr<nodes::Node> Parser::TransformToNode(
    lex::Token& input) {
  switch (input.token_kind()) {
    case lex::TokenKind::kIdentifier:
      return std::make_unique<nodes::IdentNode>(input.lexeme());
    case lex::TokenKind::kPrint:
      return std::make_unique<nodes::PrintNode>();
    case lex::TokenKind::kVar:
      return std::make_unique<nodes::VarNode>();
    default:
      std::unreachable();
  }
}
}  // namespace compiler::parse
