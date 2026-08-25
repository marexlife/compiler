#ifndef MAREX_PARSE_IDENTNODE_H
#define MAREX_PARSE_IDENTNODE_H
#include "Node.h"
#include "ParserPack.h"
#include <string>

namespace marex::parse {
class IdentNode final : public AstNode {
  public:
    explicit IdentNode(lex::Token &&token);

    [[nodiscard]] std::string as_string() override;

    void parse(ParserPack &pack) override;

  private:
    std::string value;
};
} // namespace marex::parse
#endif // MAREX_PARSE_IDENTNODE_H