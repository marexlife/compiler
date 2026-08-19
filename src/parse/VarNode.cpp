#include "VarNode.h"
#include "Logger.h"
#include <format>
#include <string>
#include <utility>

namespace marex::parse {
VarNode::VarNode(lex::Token &&token) : Node(std::move(token)) {}

std::string VarNode::asString() {
    if (identNode) [[likely]] {
        return std::format("variable {}",
                           identNode->get().asString());
    }

    core::Logger::logFatalInternalError("no value for VarNode");
}
} // namespace marex::parse