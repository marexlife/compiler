#ifndef COMPILER_PARSE_PARSER_H_
#define COMPILER_PARSE_PARSER_H_
#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>

#include "node.h"
#include "token.h"

namespace compiler::parse {
class Parser final {
  static const std::size_t kNodesDefaultReserve = 100;

 public:
  Parser() = delete;
  Parser(Parser&&) = delete;
  Parser& operator=(Parser&&) = delete;
  Parser(const Parser&) = delete;
  Parser& operator=(const Parser&) = delete;
  ~Parser() = delete;

  static void Run();

 private:
  [[nodiscard]] static std::vector<std::unique_ptr<Node>>
  TransformToNodeVector(std::vector<lex::Token>&& input);
};
}  // namespace compiler::parse
#endif  // COMPILER_PARSE_PARSER_H_
