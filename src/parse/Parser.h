#ifndef MAREX_PARSE_PARSER_H
#define MAREX_PARSE_PARSER_H
#include "JumpCont.h"
#include "Node.h"
#include "PrintNode.h"
#include "TokenStream.h"
#include "VarNode.h"
#include "Visitor.h"
#include <cstddef>

namespace marex::parse {
class Parser final {
    static const std::size_t nodesDefaultReserve = 100;

  public:
    Parser() = delete;
    Parser(Parser &&) = delete;
    Parser &operator=(Parser &&) = delete;
    Parser(const Parser &) = delete;
    Parser &operator=(const Parser &) = delete;
    ~Parser() = delete;

    static void run(lex::TokenStream &&tokenStream);

  private:
    static void processStatement(lex::Statement &statement);

    static void parseNodes(ct::VisitorVector<Node> &nodes);
    [[nodiscard]] static JumpCount parseNode(Node &previousNode,
                                             Node &currentNode);
    [[nodiscard]] static JumpCount parseVar(VarNode &self,
                                            Node &identNode);
    [[nodiscard]] static JumpCount parsePrint(PrintNode &self,
                                              Node &identNode);
};
} // namespace marex::parse
#endif // MAREX_PARSE_PARSER_H
