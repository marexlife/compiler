#ifndef MAREX_CORE_ERRORFROMATER_H
#define MAREX_CORE_ERRORFROMATER_H
#include <source_location>
#include <string>

namespace marex::core {
class ErrorFormater final {
  public:
    ErrorFormater() = delete;
    ErrorFormater(ErrorFormater &&) = delete;
    ErrorFormater &operator=(ErrorFormater &&) = delete;
    ErrorFormater(const ErrorFormater &) = delete;
    ErrorFormater &operator=(const ErrorFormater &) = delete;
    ~ErrorFormater() = delete;

    [[nodiscard]] static std::string
    merge_message_with_source_location(
        std::string_view message,
        const std::source_location &source_location);

    [[nodiscard]] static std::string source_location_to_string(
        const std::source_location &source_location);
};
} // namespace marex::core
#endif // MAREX_CORE_ERRORFROMATER_H
