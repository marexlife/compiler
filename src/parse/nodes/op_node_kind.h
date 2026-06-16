#ifndef COMPILER_PARSE_NODES_OPNODEKIND_H_
#define COMPILER_PARSE_NODES_OPNODEKIND_H_
#include <cstdint>

namespace compiler::parse::nodes {
enum class OpNodeKind : std::uint8_t {
  kNone = 0,
  kPlus,
  kMinus,
  kMul,
  kDiv,
};
}
#endif  // COMPILER_PARSE_NODES_OPNODEKIND_H_