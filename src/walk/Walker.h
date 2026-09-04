#ifndef MAREX_WALK_WALKER_H
#define MAREX_WALK_WALKER_H
#include "TranslationUnit.h"

namespace marex::walk {
class Walker final {
   public:
    static void run(
        parse::TranslationUnit&& translation_unit);
};
}  // namespace marex::walk
#endif  // MAREX_WALK_WALKER_H