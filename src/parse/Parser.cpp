#include "Parser.h"

#include "Defer.h"
#include "JumpCont.h"
#include "Logger.h"
#include "Node.h"
#include "NodeFactory.h"
#include "PrintNode.h"
#include "Statement.h"
#include "Token.h"
#include "TokenKind.h"
#include "TokenStream.h"
#include "VarNode.h"
#include <cstdint>
#include <functional>
#include <optional>
#include <utility>

namespace marex::parse {
void Parser::run(lex::TokenStream &&tokenStream) {
    for (lex::Statement &statement : tokenStream) {
        Parser::processStatement(statement);
    }
}

void Parser::processStatement(lex::Statement &statement) {
    ct::VisitorVector<Node> nodes{};

    for (lex::Token &token : statement) {
        nodes.push(NodeFactory::createNode(std::move(token)));
    }

    Parser::parseNodes(nodes);
}

void Parser::parseNodes(ct::VisitorVector<Node> &nodes) {
    std::optional<std::reference_wrapper<Node>> perviusNodeOptional =
        std::nullopt;
    JumpCount forwardJumpCount = 0;

    nodes.forEach([&](Node &node) -> void {
        core::Defer iterDefer = [&]() -> void {
            perviusNodeOptional = node;

            if (forwardJumpCount > 0) {
                --forwardJumpCount;
            }
        };

        if (perviusNodeOptional == std::nullopt ||
            forwardJumpCount != 0) {
            return;
        }

        forwardJumpCount =
            Parser::parseNode(*perviusNodeOptional, node);
    });
}

JumpCount Parser::parseNode(Node &previousNode, Node &currentNode) {
    switch (previousNode.getKind()) {
    case lex::TokenKind::Var:
        return Parser::parseVar(previousNode.cast<VarNode>(),
                                currentNode);
    case lex::TokenKind::Print:
        return Parser::parsePrint(previousNode.cast<PrintNode>(),
                                  currentNode);
    case lex::TokenKind::Identifier:
        core::Logger::logFatalError("identifier not valid here");
        break;
    case lex::TokenKind::None:
        [[fallthrough]];
    default:
        core::Logger::logFatalInternalError("invalid node kind");
        break;
    }

    return 0;
}

JumpCount Parser::parseVar([[maybe_unused]] VarNode &self,
                           [[maybe_unused]] Node &identNode) {
    return 2;
}
JumpCount Parser::parsePrint([[maybe_unused]] PrintNode &self,
                             [[maybe_unused]] Node &identNode) {
    return 2;
}
} // namespace marex::parse
