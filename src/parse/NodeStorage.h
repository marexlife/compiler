#ifndef MAREX_PARSE_NODESTORAGE_H
#define MAREX_PARSE_NODESTORAGE_H
#include "NodeVariants.h"

namespace marex::parse {
union NoadeStorage final {
    InvalidNode invalidNode;
    VarNode varNode;
    IndentNode identNode;
    PrintNode printNode;
};
} // namespace marex::parse
#endif // MAREX_PARSE_NODESTORAGE_H
