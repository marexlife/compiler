#ifndef MAREX_PARSE_PARSER_H
#define MAREX_PARSE_PARSER_H
#include "Node.h"
#include "TokenStream.h"
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

    static void run(lex::TokenStream &&tokenStream);

  private:
    static void processStatement(lex::Statement &statement);
    static void
    processNodes(std::vector<std::unique_ptr<Node>> nodes);
    static void processNode(std::unique_ptr<Node> &node);
    [[nodiscard]] static std::vector<std::unique_ptr<Node>>
    transformToNodes(lex::Statement &statement);
};
} // namespace marex::parse
#endif // MAREX_PARSE_PARSER_H
