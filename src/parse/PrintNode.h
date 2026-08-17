#ifndef MAREX_PARSE_PRINTNODE_H
#define MAREX_PARSE_PRINTNODE_H
#include "Node.h"
#include "Token.h"

namespace marex::parse {
class PrintNode final : public Node {
  public:
    explicit PrintNode(lex::Token &&token);

  private:
};
} // namespace marex::parse
#endif // MAREX_PARSE_PRINTNODE_H
