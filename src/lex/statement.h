#ifndef COMPILER_LEX_STATEMENT_H_
#define COMPILER_LEX_STATEMENT_H_
#include <cstddef>
#include <vector>

#include "token.h"

namespace compiler::lex {
class Statement final {
 public:
  Statement() = default;

  Statement(Statement&&) = default;
  Statement& operator=(Statement&&) = default;
  Statement(const Statement&) = default;
  Statement& operator=(const Statement&) = default;

  ~Statement() = default;

  void EmplaceBack(Token&& token) {
    tokens_.emplace_back(std::move(token));
  }

  auto begin() { return tokens_.begin(); }
  auto end() { return tokens_.end(); }

  auto begin() const { return tokens_.begin(); }
  auto end() const { return tokens_.end(); }

  void Clear() { tokens_.clear(); }
  void Reserve(std::size_t size) { tokens_.reserve(size); }

 private:
  std::vector<Token> tokens_;
};
}  // namespace compiler::lex
#endif  // COMPILER_LEX_STATEMENT_H_
