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
    run(lex::TokenStream &&token_stream);

  private:
    [[nodiscard]] static std::vector<std::unique_ptr<Node>>
    process_statement(lex::Statement &statement);

    static void
    parse_nodes(std::vector<std::unique_ptr<Node>> &nodes);
    [[nodiscard]] static JumpCount parse_node(Node &self,
                                              Node &next_node);

    [[nodiscard]] static JumpCount try_parse_var(VarNode &self,
                                                 Node &ident_node);
    [[nodiscard]] static JumpCount parse_var(VarNode &self,
                                             IdentNode &ident_node);

    [[nodiscard]] static JumpCount try_parse_print(PrintNode &self,
                                                   Node &ident_node);
    [[nodiscard]] static JumpCount parse_print(PrintNode &self,
                                               IdentNode &target_node);
};
} // namespace marex::parse
#endif // MAREX_PARSE_PARSER_H
