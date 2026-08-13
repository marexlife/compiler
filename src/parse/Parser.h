#ifndef MAREX_PARSE_PARSER_H
#define MAREX_PARSE_PARSER_H
#include "NodeDispatcher.h"
#include "TokenStream.h"
#include <cstddef>
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

    static void run(lex::TokenStream &&tokenStream);

  private:
    [[nodiscard]] static std::vector<NodeDispatcher>
    transformToNodes(lex::Statement &statement);
    static void processStatement(lex::Statement &statement);
    static void processNodes(std::vector<NodeDispatcher> &&nodes);
    static void processNode(NodeDispatcher &node);
};
} // namespace marex::parse
#endif // MAREX_PARSE_PARSER_H
