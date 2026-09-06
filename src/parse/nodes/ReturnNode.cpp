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

    value = std::invoke([&] -> std::string_view {
        if (pack.advance_if_matches(
                lex::TokenKind::Identifier)) {
            return pack.get_lexeme();
        }

        [[maybe_unused]] auto a =
            from_decl(pack.get_kind(), pack.get_pos());

        return "";
    });
}
}  // namespace marex::parse