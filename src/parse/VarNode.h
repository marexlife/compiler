#ifndef MAREX_PARSE_VAR_NODE_H
#define MAREX_PARSE_VAR_NODE_H
#include <functional>
#include <optional>
#include <string>

#include "ClassItem.h"
#include "IdentNode.h"
#include "ParserPack.h"
#include "Token.h"

namespace marex::parse {
class VarNode final : public ClassItem {
   public:
    explicit VarNode(lex::Token&& token);

    [[nodiscard]] std::string as_string() override;

    void parse(ParserPack& pack) override;

   private:
    std::optional<std::reference_wrapper<IdentNode>>
        ident_node = std::nullopt;
};
}  // namespace marex::parse
#endif  // MAREX_PARSE_VAR_NODE_H
