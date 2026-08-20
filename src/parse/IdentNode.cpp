#include "IdentNode.h"
#include <string>

namespace marex::parse {
[[nodiscard]] std::string IdentNode::as_string() {
    return std::string{IdentNode::get_lexeme()};
}
} // namespace marex::parse