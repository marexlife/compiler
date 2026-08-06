#ifndef COMPILER_LEX_DETAIL_CHARTABLE_H_
#define COMPILER_LEX_DETAIL_CHARTABLE_H_
namespace compiler::lex {
class CharTable final {
 public:
  CharTable() = delete;
  CharTable(CharTable&&) = delete;
  CharTable& operator=(CharTable&&) = delete;
  CharTable(const CharTable&) = delete;
  CharTable& operator=(const CharTable&) = delete;
  ~CharTable() = delete;

  static const int kSpace = ' ';
  static const int kNewLine = '\n';
};
}  // namespace compiler::lex
#endif  // COMPILER_LEX_DETAIL_CHARTABLE_H_
