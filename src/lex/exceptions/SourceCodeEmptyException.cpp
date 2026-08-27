#include "SourceCodeEmptyException.h"

namespace marex::lex {
const char*
SourceCodeEmptyException::what() const noexcept
{
    return "source code is empty";
}
} // namespace marex::lex