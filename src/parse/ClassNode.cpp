#include "ClassNode.h"

#include <utility>

#include "Logger.h"
#include "Node.h"
#include "TokenKind.h"

namespace marex::parse {
ClassNode::ClassNode(lex::Token&& token)
    : AstNode(std::move(token)) {}

[[nodiscard]] std::string ClassNode::as_string() {
    if (class_name) {
        return *class_name;
    }

    core::Logger::log_fatal_error(
        "ClassName is empty");
}

void ClassNode::parse(ParserPack& pack) {
    pack.advance_if_matches(lex::TokenKind::Class);
    class_name = pack.advance_if_matches(
        lex::TokenKind::Identifier);
}
}  // namespace marex::parse