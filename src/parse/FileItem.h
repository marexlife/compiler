#ifndef MAREX_PARSE_FILEITEM_H
#define MAREX_PARSE_FILEITEM_H
#include "AstNode.h"
#include "Token.h"

namespace marex::parse {
class FileItem : public AstNode {
public:
    explicit FileItem(lex::Token&& token);
};
} // namespace marex::parse
#endif // MAREX_PARSE_FILEITEM_H