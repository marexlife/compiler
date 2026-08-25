#ifndef MAREX_LEX_TOKENPOS_H
#define MAREX_LEX_TOKENPOS_H
#include <cstddef>
namespace marex::lex {
struct TokenPos final {
    void advance_column();
    void advance_line();

  private:
    std::size_t line{};
    std::size_t column{};
};
} // namespace marex::lex
#endif // MAREX_LEX_TOKENPOS_H