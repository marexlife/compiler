#include "ClassNode.h"

#include <utility>

#include "FileItem.h"
#include "Logger.h"
#include "TokenKind.h"

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
    core::Logger::log_info("parsing class");

    pack.advance_if_matches(lex::TokenKind::Class);
    class_name =
        pack.advance_if_matches(lex::TokenKind::Ident);
    pack.advance_if_matches(lex::TokenKind::Colon);
}
}  // namespace marex::parse