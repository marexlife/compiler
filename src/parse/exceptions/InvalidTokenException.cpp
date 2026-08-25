#include "InvalidTokenException.h"

namespace marex::parse::exceptions {
const char* InvalidTokenException::what()
    const noexcept {
    return full_message.data();
}
}  // namespace marex::parse::exceptions