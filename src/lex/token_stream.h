#ifndef COMPILER_LEX_TOKENSTREAM_H_
#define COMPILER_LEX_TOKENSTREAM_H_
#include <cstddef>
#include <vector>

#include "statement.h"
#include "token.h"

namespace compiler::lex {
class TokenStream final {
 public:
  TokenStream() = default;

  void EmplaceBack(Statement&& element) {
    statements_.emplace_back(std::move(element));
  }

  auto begin() { return statements_.begin(); }
  auto end() { return statements_.end(); }

  auto begin() const { return statements_.begin(); }
  auto end() const { return statements_.end(); }

  void Clear() { statements_.clear(); }
  void Reserve(std::size_t size) { statements_.reserve(size); }

 private:
  std::vector<Statement> statements_;
};
}  // namespace compiler::lex
#endif  // COMPILER_LEX_TOKENSTREAM_H_
