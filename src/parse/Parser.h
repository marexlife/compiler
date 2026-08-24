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

    [[nodiscard]] static std::vector<
        std::vector<std::unique_ptr<Node>>>
    run(lex::TokenStream &&token_stream);

  private:
    [[nodiscard]] static std::vector<std::unique_ptr<Node>>
    process_statement(lex::Statement &statement);

    static void set_nodes(std::vector<std::unique_ptr<Node>> &nodes);
};
} // namespace marex::parse
#endif // MAREX_PARSE_PARSER_H
