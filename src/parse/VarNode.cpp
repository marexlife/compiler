#include "VarNode.h"

#include <format>
#include <string>
#include <utility>

#include "ClassItem.h"
#include "Logger.h"
#include "ParserPack.h"

namespace marex::parse {
VarNode::VarNode(lex::Token&& token)
    : ClassItem(std::move(token)) {}

std::string VarNode::as_string() {
    if (ident_node) [[likely]] {
        return std::format(
            "variable {}",
            ident_node->get().as_string());
    }

    core::Logger::log_fatal_internal_error(
        "no value for VarNode");
}

void VarNode::parse(
    [[maybe_unused]] ParserPack& pack) {}
}  // namespace marex::parse