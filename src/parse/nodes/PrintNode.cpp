#include "PrintNode.h"

#include <format>
#include <utility>

#include "Parsable.h"
#include "ParserPack.h"
#include "TokenKind.h"

namespace marex::parse {
PrintNode::PrintNode(lex::Token&& token)
    : Parsable(std::move(token)) {}

std::string PrintNode::as_c() {
    return std::format("printf(\"{}\");\n", message);
}

void PrintNode::parse(ParserPack& pack) {
    pack.advance_if_matches_or_throw(
        lex::TokenKind::Print);

    message = pack.advance_if_matches_or_throw(
        lex::TokenKind::Identifier);
}
}  // namespace marex::parse