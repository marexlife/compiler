#include "ErorrFormater.h"
#include <format>

namespace marex::core {
std::string ErrorFromater::mergeMessageWithSourceLocation(
    std::string_view message,
    const std::source_location &sourceLocation) {
    return std::format(
        "{}\n{}", message,
        ErrorFromater::sourceLocationToString(sourceLocation));
}

std::string ErrorFromater::sourceLocationToString(
    const std::source_location &sourceLocation) {
    return std::format(
        "at: {}, {}, {}:{}", sourceLocation.file_name(),
        sourceLocation.function_name(), sourceLocation.line(),
        sourceLocation.column());
}
} // namespace marex::core
