#include "PrintNode.h"
#include "IdentNode.h"
#include "Logger.h"
#include <format>
#include <utility>

namespace marex::parse {
PrintNode::PrintNode(lex::Token &&token) : Node(std::move(token)) {}

std::string PrintNode::asString() {
    if (identNode) [[likely]] {
        return std::format("print {}", identNode->get().asString());
    }

    core::Logger::logFatalInternalError("no value for print node");
}
} // namespace marex::parse