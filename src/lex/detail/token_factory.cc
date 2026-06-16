#include "token_factory.h"

#include <absl/strings/string_view.h>

namespace compiler::lex {
absl::StatusOr<Token> TokenFactory::CreateToken(
    std::basic_string_view<int> source_word) {

}
}  // namespace compiler::lex