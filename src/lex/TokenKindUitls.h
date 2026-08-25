#ifndef MAREX_LEX_TOKENKINDUTILS_H
#define MAREX_LEX_TOKENKINDUTILS_H
#include <string_view>

#include "TokenKind.h"

namespace marex::lex {
[[nodiscard]] std::string_view get_token_kind_name(
    TokenKind token_kind);
}
#endif // MAREX_LEX_TOKENKINDUTILS_H