#include "PrintNode.h"

#include <format>
#include <utility>

#include "Logger.h"
#include "ParserPack.h"
#include "nodes/FileItem.h"

namespace marex::parse {
PrintNode::PrintNode(lex::Token&& token)
    : FileItem(std::move(token)) {}

std::string PrintNode::as_string() {
    if (ident_node) [[likely]] {
        return std::format(
            "print {}", ident_node->get().as_string());
    }

    core::Logger::log_fatal_internal_error(
        "no value for print node");
}

void PrintNode::parse(
    [[maybe_unused]] ParserPack& pack) {}
}  // namespace marex::parse