#ifndef MAREX_CORE_ERRORFROMATER_H
#define MAREX_CORE_ERRORFROMATER_H
#include <source_location>
#include <string>

namespace marex::core {
class ErrorFromater final {
  public:
    [[nodiscard]] static std::string mergeMessageWithSourceLocation(
        std::string_view message,
        const std::source_location &sourceLocation);

    [[nodiscard]] static std::string sourceLocationToString(
        const std::source_location &sourceLocation);
};
} // namespace marex::core
#endif // MAREX_CORE_ERRORFROMATER_H
