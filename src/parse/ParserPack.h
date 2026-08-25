#ifndef MAREX_PARSE_PARSERPACK_H
#define MAREX_PARSE_PARSERPACK_H
#include "TokenStream.h"

namespace marex::parse {
struct ParserPack final {
    [[nodiscard]] std::size_t get_progress() const {
        return progress;
    }

    template <typename Fn>
        requires std::is_invocable_v<Fn>
    void advance_if(Fn advancer) {
        advancer();
    }

  private:
    lex::TokenStream token_stream;
    std::size_t progress{};
};
} // namespace marex::parse
#endif // MAREX_PARSE_PARSERPACK_H