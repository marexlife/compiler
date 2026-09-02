#ifndef MAREX_LEX_TOKENKINDUTILS_H
#define MAREX_LEX_TOKENKINDUTILS_H
#include <string_view>

#include "TokenKind.h"

namespace marex::lex {
[[nodiscard]] std::string_view token_kind_to_string(
    TokenKind token_kind);
}
#endif  // MAREX_LEX_TOKENKINDUTILS_H