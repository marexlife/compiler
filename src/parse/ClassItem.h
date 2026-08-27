#ifndef MAREX_PARSE_CLASSITEM_H
#define MAREX_PARSE_CLASSITEM_H
#include "FileItem.h"
#include "Token.h"

namespace marex::parse {
class ClassItem : public FileItem {
   public:
    explicit ClassItem(lex::Token&& token);
};
}  // namespace marex::parse
#endif  // MAREX_PARSE_CLASSITEM_H