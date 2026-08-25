#include "PrintNode.h"
#include "IdentNode.h"
#include "Logger.h"
#include "ParserPack.h"
#include <format>
#include <utility>

namespace marex::parse {
PrintNode::PrintNode(lex::Token &&token)
    : AstNode(std::move(token)) {}

std::string PrintNode::as_string() {
    if (ident_node) [[likely]] {
        return std::format("print {}", ident_node->get().as_string());
    }

    core::Logger::log_fatal_internal_error("no value for print node");
}

void PrintNode::parse([[maybe_unused]] ParserPack &pack) {}
} // namespace marex::parse