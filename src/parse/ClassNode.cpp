#include "ClassNode.h"

#include <format>
#include <memory>
#include <string>
#include <utility>

#include "ClassItem.h"
#include "FileItem.h"
#include "FuncNode.h"
#include "Logger.h"
#include "ParserPack.h"
#include "TokenKind.h"
#include "VarNode.h"
#include "exceptions/InvalidTokenException.h"

namespace marex::parse {
ClassNode::ClassNode(lex::Token&& token)
    : FileItem(std::move(token)) {}

[[nodiscard]] std::string ClassNode::as_string() {
    if (class_name) {
        return *class_name;
    }

    core::Logger::log_fatal_error(
        "ClassName is empty");
}

void ClassNode::parse(ParserPack& pack) {
    parse_class_signature(pack);
    parse_class_body(pack);
}

void ClassNode::parse_class_signature(
    ParserPack& pack) {
    pack.advance_if_matches_or_throw(
        lex::TokenKind::Class);
    class_name = pack.advance_if_matches_or_throw(
        lex::TokenKind::Identifier);

    if (pack.advance_if_matches(
            lex::TokenKind::Colon)) {
        core::Logger::log_info(std::format(
            "parsed class signature from class '{}' "
            "without parent class",
            *class_name));

        return;
    }

    pack.advance_if_matches_or_throw(
        lex::TokenKind::OpenBracket);
    parent_class_name =
        pack.advance_if_matches_or_throw(
            lex::TokenKind::Identifier);
    pack.advance_if_matches_or_throw(
        lex::TokenKind::CloseBracket);
    pack.advance_if_matches_or_throw(
        lex::TokenKind::Colon);

    core::Logger::log_info(std::format(
        "parsed class signature from class '{}' "
        "with parent class '{}'",
        *class_name, *parent_class_name));
}

void ClassNode::parse_class_body(ParserPack& pack) {
    while (!pack.is_at_end()) {
        auto class_entry = visit_class_entry(pack);

        class_entry->parse(pack);

        class_items.emplace_back(
            std::move(class_entry));
    }
}

std::unique_ptr<ClassItem>
ClassNode::visit_class_entry(ParserPack& pack) {
    switch (pack.get_kind()) {
        case lex::TokenKind::Func:
        case lex::TokenKind::Var:
            return std::make_unique<VarNode>(
                pack.copy_out_token());
        case lex::TokenKind::Class:
            throw exceptions::InvalidTokenException(
                pack.get_pos(),
                "class in class not allowed");
        default:
            throw exceptions::InvalidTokenException(
                pack.get_pos(),
                std::string{pack.get_kind_string()});
    }
}
}  // namespace marex::parse
