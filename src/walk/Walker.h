#ifndef MAREX_WALK_WALKER_H
#define MAREX_WALK_WALKER_H
#include "Node.h"
#include <memory>
#include <vector>

namespace marex::walk {
class Walker final {
  public:
    static void
    run(std::vector<std::vector<std::unique_ptr<parse::Node>>>
            &&list_of_nodes);
};
} // namespace marex::walk
#endif // MAREX_WALK_WALKER_H