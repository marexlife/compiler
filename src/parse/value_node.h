#ifndef COMPILER_PARSE_VALUENODE_H
#define COMPILER_PARSE_VALUENODE_H
#include <type_traits>
#include <utility>

#include "node.h"

namespace compiler::parse 
{
template <typename WrappedType, typename Tag = WrappedType>
  requires std::is_move_constructible_v<WrappedType> &&
           std::is_default_constructible_v<WrappedType>
class ValueNode : public Node 
{
  public:
    explicit ValueNode(WrappedType&& value)
        : value(std::move(value)) {}

    [[nodiscard]] const WrappedType& value() const { return value; }

 private:
    WrappedType value{};
};
}  // namespace compiler::parse
#endif  // COMPILER_PARSE_VALUENODE_H
