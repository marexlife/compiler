#ifndef MAREX_PARSE_DUOOPNODE_H
#define MAREX_PARSE_DUOOPNODE_H
#include "OpNode.h"
#include "Token.h"

namespace marex::parse {
class DuoOpNode : public OpNode {
   public:
    explicit DuoOpNode(lex::Token&& token);

   private:
};
}  // namespace marex::parse
#endif  // MAREX_PARSE_DUOOPNODE_H