#ifndef COMPILER_PARSE_OPNODEKIND_H_
#define COMPILER_PARSE_OPNODEKIND_H_
#include <cstdint>

namespace compiler::parse 
{
enum class [[nodiscard]] OpNodeKind : std::uint8_t 
{
	None = 0,
	Plus,
	Minus,
	Multiply,
	Divide,
};
}
#endif  // COMPILER_PARSE_OPNODEKIND_H_
