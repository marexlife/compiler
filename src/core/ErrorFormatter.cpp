#include "ErrorFormatter.h"
#include <format>

namespace marex::core {
std::string
ErrorFormater::merge_message_with_source_location(
    std::string_view message,
    const std::source_location& source_location)
{
    return std::format("{}\n{}",
        ErrorFormater::source_location_to_string(
            source_location),
        message);
}

std::string ErrorFormater::source_location_to_string(
    const std::source_location& source_location)
{
    return std::format("\nat {}:{}:{}",
        source_location.file_name(),
        source_location.line(),
        source_location.column());
}
} // namespace marex::core
