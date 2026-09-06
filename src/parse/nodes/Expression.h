#ifndef MAREX_PARSE_EXPRESSION_H
#define MAREX_PARSE_EXPRESSION_H
#include "Parsable.h"
#include "Token.h"

namespace marex::parse {
class Expression : public AstNode {
   public:
    explicit Expression(lex::Token&& token);

   private:
};
}  // namespace marex::parse
#endif  // MAREX_PARSE_EXPRESSION_H