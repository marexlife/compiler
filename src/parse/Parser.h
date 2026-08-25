#ifndef MAREX_PARSE_PARSER_H
#define MAREX_PARSE_PARSER_H
#include "ParserPack.h"
#include "TokenStream.h"
#include <cstddef>

namespace marex::parse {
class Parser final {
    static const std::size_t nodes_default_reserve = 100;

  public:
    Parser() = delete;
    Parser(Parser &&) = delete;
    Parser &operator=(Parser &&) = delete;
    Parser(const Parser &) = delete;
    Parser &operator=(const Parser &) = delete;
    ~Parser() = delete;

    static void run(lex::TokenStream &&token_stream);

  private:
    static void parse(ParserPack &&pack);
};
} // namespace marex::parse
#endif // MAREX_PARSE_PARSER_H
