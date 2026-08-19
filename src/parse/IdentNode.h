#ifndef MAREX_PARSE_IDENTNODE_H
#define MAREX_PARSE_IDENTNODE_H
#include "Node.h"
#include <string>

namespace marex::parse {
class IdentNode final : public Node {
  public:
    [[nodiscard]] std::string asString();

  private:
};
} // namespace marex::parse
#endif // MAREX_PARSE_IDENTNODE_H