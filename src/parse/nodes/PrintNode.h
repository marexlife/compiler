#ifndef MAREX_PARSE_PRINTNODE_H
#define MAREX_PARSE_PRINTNODE_H
#include <string>

#include "AstNode.h"
#include "ParserPack.h"
#include "Token.h"

namespace marex::parse {
class PrintNode final : public Parsable {
   public:
    explicit PrintNode(lex::Token&& token);

    [[nodiscard]] std::string as_c() override;

    void parse(ParserPack& pack) override;

   private:
    std::string message;
};
}  // namespace marex::parse
#endif  // MAREX_PARSE_PRINTNODE_H
