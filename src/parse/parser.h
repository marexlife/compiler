#ifndef COMPILER_PARSE_PARSER_H_
#define COMPILER_PARSE_PARSER_H_
namespace compiler::parse {
class Parser final {
public:
  Parser() = delete;
  Parser(Parser&&) = delete;
  Parser& operator=(Parser&&) = delete;
  Parser(const Parser&) = delete;
  Parser& operator=(const Parser&) = delete;
  ~Parser() = delete;

  static void Run();
};
}
#endif  // COMPILER_PARSE_PARSER_H_
