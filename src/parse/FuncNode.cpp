#include "FuncNode.h"

#include <stdexcept>
#include <utility>

#include "FileItem.h"
#include "ParserPack.h"
#include "TokenKind.h"
#include "TypeKind.h"

namespace marex::parse {
FuncNode::FuncNode(lex::Token&& token)
    : FileItem(std::move(token)) {}

[[nodiscard]] std::string FuncNode::as_string() {
    return "func node";
}

void FuncNode::parse(
    [[maybe_unused]] ParserPack& pack) {
    parse_func_signature(pack);
    parse_func_body(pack);
}

void FuncNode::parse_func_signature(ParserPack& pack) {
    pack.advance_if_matches(lex::TokenKind::Func);
    pack.advance_if_matches(
        lex::TokenKind::Identifier);
    pack.advance_if_matches(
        lex::TokenKind::OpenBracket);
    pack.advance_if_matches(
        lex::TokenKind::CloseBracket);

    if (pack.matches(lex::TokenKind::OpenBrace)) {
        type_kind = TypeKind::EmptyType;
    }

    throw std::runtime_error("not implemented yet");
}

void FuncNode::parse_func_body(
    [[maybe_unused]] ParserPack& pack) {}
}  // namespace marex::parse
