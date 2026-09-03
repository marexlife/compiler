#include "ClassItem.h"

#include <utility>

#include "FileItem.h"
#include "Token.h"

namespace marex::parse {
ClassItem::ClassItem(lex::Token&& token)
    : FileItem(std::move(token)) {}
}  // namespace marex::parse