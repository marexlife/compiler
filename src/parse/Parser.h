#ifndef MAREX_PARSE_PARSER_H
#define MAREX_PARSE_PARSER_H
#include "Node.h"
#include "TokenStream.h"
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
    static void processNodes(ct::VisitorVector<Node> &nodes);
    static void processNode(Node &node);
};
} // namespace marex::parse
#endif // MAREX_PARSE_PARSER_H
