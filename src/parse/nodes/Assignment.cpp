#include "Assignment.h"

#include <stdexcept>
#include <string>

#include "ParserPack.h"

namespace marex::parse {
std::string Assignment::as_c() {
    throw std::runtime_error(
        "Assignment as_c not implemented yet");
}

void Assignment::parse(
    [[maybe_unused]] ParserPack& pack) {
    
    }
}  // namespace marex::parse