#include "Node.h"

namespace marex::parse {
[[nodiscard]] Node Node::createNode(lex::Token &token) {
    switch (token.getKind()) {
    case lex::TokenKind::Identifier:

        break;
    case lex::TokenKind::Print:
        break;
    case lex::TokenKind::Var:
        break;
    case lex::TokenKind::None:
        goto fail;
    }

fail:
    core::Logger::logFatalInternalError("unhandled enum value",
                                        std::source_location{});
}
} // namespace marex::parse