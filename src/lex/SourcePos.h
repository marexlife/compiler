#ifndef MAREX_LEX_TOKENPOS_H
#define MAREX_LEX_TOKENPOS_H
#include <cstddef>
#include <string>

namespace marex::lex {
struct SourcePos final {
    void advance_column();
    void advance_line();

    [[nodiscard]] std::string to_string() const;

   private:
    std::size_t line{};
    std::size_t column{};
};
}  // namespace marex::lex
#endif  // MAREX_LEX_TOKENPOS_H