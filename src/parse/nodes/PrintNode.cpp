#include "PrintNode.h"

#include <format>
#include <stdexcept>
#include <utility>

#include "Logger.h"
#include "ParserPack.h"
#include "nodes/FileItem.h"

namespace marex::parse {
PrintNode::PrintNode(lex::Token&& token)
    : FileItem(std::move(token)) {}

std::string PrintNode::as_string() {
    throw std::runtime_error("not implemented yet");
}

void PrintNode::parse(
    [[maybe_unused]] ParserPack& pack) {}
}  // namespace marex::parse