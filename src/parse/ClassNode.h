#ifndef MAREX_PARSE_CLASSNODE_H
#define MAREX_PARSE_CLASSNODE_H
#include <string>

#include "Node.h"
#include "Token.h"

namespace marex::parse {
class ClassNode final : public AstNode {
   public:
    explicit ClassNode(lex::Token&& token);

    [[nodiscard]] std::string as_string() override;

    void parse(ParserPack& pack) override;

   private:
    std::string class_name;
};
}  // namespace marex::parse
#endif  // MAREX_PARSE_CLASSNODE_H