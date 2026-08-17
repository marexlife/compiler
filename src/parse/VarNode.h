#ifndef MAREX_PARSE_VAR_NODE_H
#define MAREX_PARSE_VAR_NODE_H
#include "Node.h"
#include "Token.h"

namespace marex::parse {
class VarNode final : public Node {
  public:
    explicit VarNode(lex::Token &&token);
};
} // namespace marex::parse
#endif // MAREX_PARSE_VAR_NODE_H
