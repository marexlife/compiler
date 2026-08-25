#include "FuncNode.h"

namespace marex::parse {
[[nodiscard]] std::string FuncNode::as_string() {
    return "func";
}

void FuncNode::parse(
    [[maybe_unused]] ParserPack& pack) {}
}  // namespace marex::parse
