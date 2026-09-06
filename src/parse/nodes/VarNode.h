#ifndef MAREX_PARSE_VAR_NODE_H
#define MAREX_PARSE_VAR_NODE_H
#include <string>

#include "ExpressionKind.h"
#include "Parsable.h"
#include "ParserPack.h"
#include "Token.h"


namespace marex::parse {
class VarNode final : public Parsable {
   public:
    explicit VarNode(lex::Token&& token);

   protected:
    [[nodiscard]] std::string as_c() override;

    void parse(ParserPack& pack) override;

   private:
    std::string name;
    ExpressionKind type_kind{};
    std::string value;
};
}  // namespace marex::parse
#endif  // MAREX_PARSE_VAR_NODE_H
