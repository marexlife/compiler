#ifndef COMPILER_PARSE_VALUENODE_H
#define COMPILER_PARSE_VALUENODE_H
#include <utility>

#include "Node.h"

namespace compiler::parse {
template <typename WrappedType> class ValueNode : public Node {
  public:
    explicit ValueNode(WrappedType &&value)
        : value(std::move(value)) {}

    [[nodiscard]] const WrappedType &getValue() const {
        return value;
    }

  private:
    WrappedType value{};
};
} // namespace compiler::parse
#endif // COMPILER_PARSE_VALUENODE_H
