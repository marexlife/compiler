#ifndef MAREX_PARSE_PARSER_H
#define MAREX_PARSE_PARSER_H
#include "IdentNode.h"
#include "JumpCont.h"
#include "Node.h"
#include "PrintNode.h"
#include "TokenStream.h"
#include "VarNode.h"
#include <cstddef>
#include <memory>
#include <vector>

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

    [[nodiscard]] static std::vector<
        std::vector<std::unique_ptr<Node>>>
    run(lex::TokenStream &&tokenStream);

  private:
    [[nodiscard]] static std::vector<std::unique_ptr<Node>>
    processStatement(lex::Statement &statement);

    static void parseNodes(std::vector<std::unique_ptr<Node>> &nodes);
    [[nodiscard]] static JumpCount parseNode(Node &previousNode,
                                             Node &currentNode);

    [[nodiscard]] static JumpCount tryParseVar(VarNode &self,
                                               Node &identNode);
    [[nodiscard]] static JumpCount parseVar(VarNode &self,
                                            IdentNode &identNode);

    [[nodiscard]] static JumpCount tryParsePrint(PrintNode &self,
                                                 Node &identNode);
    [[nodiscard]] static JumpCount parsePrint(PrintNode &self,
                                              IdentNode &targetNode);
};
} // namespace marex::parse
#endif // MAREX_PARSE_PARSER_H
