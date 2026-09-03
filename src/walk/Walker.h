#ifndef MAREX_WALK_WALKER_H
#define MAREX_WALK_WALKER_H
#include <memory>
#include <vector>

#include "nodes/AstNode.h"

namespace marex::walk {
class Walker final {
   public:
    static void
    run(std::vector<
        std::vector<std::unique_ptr<parse::AstNode>>>&&
            list_of_nodes);
};
}  // namespace marex::walk
#endif  // MAREX_WALK_WALKER_H