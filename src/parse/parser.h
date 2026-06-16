#ifndef COMPILER_PARSE_PARSER_H_
#define COMPILER_PARSE_PARSER_H_
#include <cstddef>
#include <memory>

#include "absl/container/inlined_vector.h"
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
  [[nodiscard]] static absl::InlinedVector<std::unique_ptr<Node>,
                                           kNodesDefaultReserve>
  TransformToNodeVector(
      absl::InlinedVector<lex::Token, kNodesDefaultReserve>&& input);

  [[nodiscard]] static std::unique_ptr<Node> TransformToNode(lex::Token& input);
};
}  // namespace compiler::parse
#endif  // COMPILER_PARSE_PARSER_H_
