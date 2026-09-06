#ifndef MAREX_PARSE_IDENTNODE_H
#define MAREX_PARSE_IDENTNODE_H
#include <string>

#include "Parsable.h"
#include "ParserPack.h"

namespace marex::parse {
class IdentNode final : public Parsable {
   public:
    explicit IdentNode(lex::Token&& token);

    [[nodiscard]] std::string as_c() override;

    void parse(ParserPack& pack) override;

   private:
    std::string value;
};
}  // namespace marex::parse
#endif  // MAREX_PARSE_IDENTNODE_H