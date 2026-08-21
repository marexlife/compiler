#ifndef MAREX_PARSE_IDENTNODE_H
#define MAREX_PARSE_IDENTNODE_H
#include "Node.h"
#include <string>

namespace marex::parse {
class IdentNode final : public Node {
  public:
    explicit IdentNode(lex::Token &&token);

    [[nodiscard]] std::string as_string();

    [[nodiscard]] static JumpCount parse();

  private:
    std::string value;
};
} // namespace marex::parse
#endif // MAREX_PARSE_IDENTNODE_H