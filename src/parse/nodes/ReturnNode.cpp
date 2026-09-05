#include "ReturnNode.h"

#include <format>
#include <stdexcept>
#include <string>
#include <utility>

#include "ParserPack.h"
#include "Token.h"
#include "TokenKind.h"
#include "nodes/FileItem.h"

namespace marex::parse {
ReturnNode::ReturnNode(lex::Token&& token)
    : FileItem(std::move(token)) {}

std::string ReturnNode::as_c() {
    if (value) {
        return std::format("return {};",
                           value.value());
    }

    throw std::runtime_error(
        "no value in return node");
}

void ReturnNode::parse(ParserPack& pack) {
    pack.advance_if_matches_or_throw(
        lex::TokenKind::Return);
    value = pack.advance_if_matches_or_throw(
        lex::TokenKind::Identifier);
}
}  // namespace marex::parse