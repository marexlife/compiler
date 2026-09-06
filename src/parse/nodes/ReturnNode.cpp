#include "ReturnNode.h"

#include <format>
#include <functional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>

#include "ExpressionKind.h"
#include "ParserPack.h"
#include "Token.h"
#include "TokenKind.h"

namespace marex::parse {
ReturnNode::ReturnNode(lex::Token&& token)
    : Parsable(std::move(token)) {}

std::string ReturnNode::as_c() {
    if (!value) {
        throw std::runtime_error(
            "no value in return node");
    }

    return std::format("return {};", value.value());
}

void ReturnNode::parse(ParserPack& pack) {
    pack.advance_if_matches_or_throw(
        lex::TokenKind::Return);

    expression_kind =
        expression_kind_from_literal_or_throw(pack);

    value = pack.get_lexeme_and_advance();
}
}  // namespace marex::parse