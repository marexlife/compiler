#ifndef MAREX_PARSE_CLASSITEM_H
#define MAREX_PARSE_CLASSITEM_H
#include "Node.h"
#include "Token.h"

namespace marex::parse {
class ClassItem : public AstNode {
   public:
    explicit ClassItem(lex::Token&& token);
};
}  // namespace marex::parse
#endif  // MAREX_PARSE_CLASSITEM_H