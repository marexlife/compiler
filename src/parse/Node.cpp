#include "Node.h"

namespace marex::parse {
[[nodiscard]] static Node createNode(lex::Token &token) {
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
    core::Logger::logFatalInternalError("invalid enum value");
}
} // namespace marex::parse