#include "IdentNode.h"
#include <string>

namespace marex::parse {
[[nodiscard]] std::string IdentNode::asString() {
    return std::string{IdentNode::getLexeme()};
}
} // namespace marex::parse