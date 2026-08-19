#include "Walker.h"
#include "IdentNode.h"
#include "Logger.h"
#include "Node.h"
#include "TokenKind.h"
#include <memory>

namespace marex::walk {
void Walker::run(
    std::vector<std::vector<std::unique_ptr<parse::Node>>>
        &&listOfNodes) {
    for (auto &nodes : listOfNodes) {
        for (std::unique_ptr<parse::Node> &node : nodes) {
            switch (node->getKind()) {
            case marex::lex::TokenKind::Identifier:
                node->cast<parse::IdentNode>().print();
                break;
            case marex::lex::TokenKind::Print:
                break;
            case marex::lex::TokenKind::Var:
                break;
            case marex::lex::TokenKind::None:
                [[fallthrough]];
            default:
                core::Logger::logFatalInternalError(
                    "not a valid Node");
            }
        }
    }
}
} // namespace marex::walk