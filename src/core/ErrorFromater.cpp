#include "ErorrFormater.h"
#include <format>

namespace marex::core {
std::string ErrorFromater::mergeMessageWithSourceLocation(
    std::string_view message,
    const std::source_location &sourceLocation) {
    return std::format(
        "{}\n{}",
        ErrorFromater::sourceLocationToString(sourceLocation),
        message);
}

std::string ErrorFromater::sourceLocationToString(
    const std::source_location &sourceLocation) {
    return std::format("at: {}:{}:{}", sourceLocation.file_name(),
                       sourceLocation.line(),
                       sourceLocation.column());
}
} // namespace marex::core
