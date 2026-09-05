#include "PrintNode.h"

#include <format>
#include <utility>

#include "ParserPack.h"
#include "TokenKind.h"
#include "nodes/FileItem.h"

namespace marex::parse {
PrintNode::PrintNode(lex::Token&& token)
    : FileItem(std::move(token)) {}

std::string PrintNode::as_string() {
    return std::format("printf(\"{}\");\n", message);
}

void PrintNode::parse(ParserPack& pack) {
    pack.advance_if_matches_or_throw(
        lex::TokenKind::Print);

    message = pack.advance_if_matches_or_throw(
        lex::TokenKind::Identifier);
}
}  // namespace marex::parse