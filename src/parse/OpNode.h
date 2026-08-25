#ifndef MAREX_PARSE_OPNODE_H
#define MAREX_PARSE_OPNODE_H
#include "Node.h"
#include "Token.h"

namespace marex::parse {
class OpNode : public AstNode {
public:
    explicit OpNode(lex::Token&& token);

private:
};
} // namespace marex::parse
#endif // MAREX_PARSE_OPNODE_H
