#include "FileItem.h"

#include <utility>

namespace marex::parse {
FileItem::FileItem(lex::Token&& token)
    : AstNode(std::move(token))
{
}
} // namespace marex::parse