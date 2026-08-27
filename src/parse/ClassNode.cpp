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
    core::Logger::log_info(
        "now expecteing a class name");

    class_name =
        pack.advance_if_matches(lex::TokenKind::Ident);

    core::Logger::log_info("now expecteing a colon");
    pack.advance_if_matches(lex::TokenKind::Colon);

    core::Logger::log_info("end parsing class");
}
}  // namespace marex::parse
