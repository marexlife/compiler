#include "InvalidTokenException.h"

namespace marex::parse::exceptions {
InvalidTokenException::InvalidTokenException(std::string &&message)
    : message(std::move(message)) {}

const char *InvalidTokenException::what() const noexcept {
    return message.data();
}
} // namespace marex::parse::exceptions