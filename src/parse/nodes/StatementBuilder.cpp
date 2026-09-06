#include "StatementBuilder.h"

#include <cstddef>

#include "ParserPack.h"
#include "TokenKind.h"

namespace marex::parse {
void StatementBuilder::build(
    [[maybe_unused]] ParserPack& pack) {
    for (std::size_t i = 0;
         pack.token_kind_at(i) !=
         lex::TokenKind::StatementEnd;
         ++i) {
    }
}
}  // namespace marex::parse