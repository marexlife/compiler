#include "Walker.h"

namespace marex::walk {
void Walker::run(
    parse::TranslationUnit&& translation_unit) {
    std::cout << "output:\n";
    std::cout << translation_unit.as_string();
}
}  // namespace marex::walk