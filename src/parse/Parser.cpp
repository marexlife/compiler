#include "Parser.h"

#include "Defer.h"
#include "IdentNode.h"
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
#include <functional>
#include <memory>
#include <optional>
#include <utility>

namespace marex::parse {
void Parser::run(lex::TokenStream &&tokenStream) {
    for (lex::Statement &statement : tokenStream) {
        Parser::processStatement(statement);
    }
}

void Parser::processStatement(lex::Statement &statement) {
    std::vector<std::unique_ptr<Node>> nodes{};

    for (lex::Token &token : statement) {
        nodes.emplace_back(NodeFactory::createNode(std::move(token)));
    }

    Parser::parseNodes(nodes);
}

void Parser::parseNodes(std::vector<std::unique_ptr<Node>> &nodes) {
    std::optional<std::reference_wrapper<Node>> perviousNodeOptional =
        std::nullopt;
    JumpCount forwardJumpCount = 0;

    for (std::unique_ptr<Node> &node : nodes) {
        core::Defer iterDefer = [&]() -> void {
            perviousNodeOptional = *node;

            if (forwardJumpCount > 0) {
                --forwardJumpCount;
            }
        };

        if (perviousNodeOptional == std::nullopt ||
            forwardJumpCount != 0) {
            continue;
        }

        forwardJumpCount =
            Parser::parseNode(*perviousNodeOptional, *node);
    }
}

JumpCount Parser::parseNode(Node &previousNode, Node &currentNode) {
    switch (previousNode.getKind()) {
    case lex::TokenKind::Var:
        return Parser::tryParseVar(previousNode.cast<VarNode>(),
                                   currentNode);
    case lex::TokenKind::Print:
        return Parser::tryParsePrint(previousNode.cast<PrintNode>(),
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

JumpCount Parser::tryParseVar(VarNode &self, Node &identNode) {
    switch (identNode.getKind()) {
    case marex::lex::TokenKind::Identifier:
        return Parser::parseVar(self, identNode.cast<IdentNode>());
    default:
        core::Logger::logFatalError(
            "wrong thing after var. try: var x");
    }
}

JumpCount Parser::parseVar(VarNode &self, IdentNode &identNode) {
    self.setIdentNode(identNode);

    return 2;
}

JumpCount Parser::tryParsePrint(PrintNode &self, Node &identNode) {
    switch (self.getKind()) {
    case marex::lex::TokenKind::Identifier:
        return Parser::parsePrint(self, identNode.cast<IdentNode>());
    default:
        core::Logger::logFatalError(
            "wrong thing after var. try: print hey");
    }
}

JumpCount Parser::parsePrint(PrintNode &self, IdentNode &targetNode) {
    self.setTargetNode(targetNode);

    return 2;
}
} // namespace marex::parse
