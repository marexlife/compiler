#include "VarNode.h"
#include "Logger.h"
#include <format>
#include <string>
#include <utility>

namespace marex::parse {
VarNode::VarNode(lex::Token &&token) : Node(std::move(token)) {}

std::string VarNode::as_string() {
    if (identNode) [[likely]] {
        return std::format("variable {}",
                           identNode->get().as_string());
    }

    core::Logger::log_fatal_internal_error("no value for VarNode");
}
} // namespace marex::parse