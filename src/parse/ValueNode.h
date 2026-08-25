#ifndef MAREX_PARSE_VALUENODE_H
#define MAREX_PARSE_VALUENODE_H
#include <utility>

#include "Node.h"

namespace marex::parse {
template <typename WrappedType, typename Tag>
class ValueNode : public AstNode {
  public:
    explicit ValueNode(WrappedType &&value)
        : value(std::move(value)) {}

    [[nodiscard]] const WrappedType &get_value() const {
        return value;
    }

  private:
    WrappedType value{};
};
} // namespace marex::parse
#endif // MAREX_PARSE_VALUENODE_H
