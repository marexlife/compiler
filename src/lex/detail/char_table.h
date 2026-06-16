#ifndef COMPILER_LEX_DETAIL_CHARTABLE_H_
#define COMPILER_LEX_DETAIL_CHARTABLE_H_
namespace compiler::lex::detail {
class char_table final {
public:
    char_table() = delete;
    char_table(char_table&&) = delete;
    char_table& operator=(char_table&&) = delete;
    char_table(const char_table&) = delete;
    char_table& operator=(const char_table&) = delete;
    ~char_table() = delete;

    static const int space = ' ';
    static const int new_line = '\n';
};
} // namespace compiler::lex::detail
#endif // COMPILER_LEX_DETAIL_CHARTABLE_H_