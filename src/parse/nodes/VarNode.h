#ifndef MAREX_PARSE_VAR_NODE_H
#define MAREX_PARSE_VAR_NODE_H
#include <string>

#include "ClassItem.h"
#include "ParserPack.h"
#include "Token.h"
#include "TypeKind.h"

namespace marex::parse {
class VarNode final : public ClassItem {
   public:
    explicit VarNode(lex::Token&& token);

    [[nodiscard]] std::string as_string() override;

    void parse(ParserPack& pack) override;

   private:
    std::string name;
    TypeKind type_kind{};
    std::string value;
};
}  // namespace marex::parse
#endif  // MAREX_PARSE_VAR_NODE_H
