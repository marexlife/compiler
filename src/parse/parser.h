#ifndef COMPILER_PARSE_PARSER_H_
#define COMPILER_PARSE_PARSER_H_
#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>

#include "nodes/node.h"
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
  [[nodiscard]] static std::vector<std::unique_ptr<nodes::Node>>
  TransformToNodeVector(std::vector<lex::Token>&& input);

  [[nodiscard]] static std::vector<std::int8_t> ToBindingPowerVec(
      std::vector<lex::Token>& tokens);
  [[nodiscard]] static std::int8_t ToBindingPower(lex::Token& token);

  [[nodiscard]] static std::unique_ptr<nodes::Node> TransformToNode(
      lex::Token& input);
};
}  // namespace compiler::parse
#endif  // COMPILER_PARSE_PARSER_H_
