#ifndef COMPILER_LEX_TOKENSTREAM_H_
#define COMPILER_LEX_TOKENSTREAM_H_
#include <list>
#include <vector>

#include "token.h"

namespace compiler::lex {
class TokenStream final {
 public:
  void EmplaceBack(Token&& token) {
    tokens_.emplace_back(std::move(token));
  }

 private:
  std::vector<Token> tokens_;
};
}  // namespace compiler::lex
#endif  // COMPILER_LEX_TOKENSTREAM_H_
