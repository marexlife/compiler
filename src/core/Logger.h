#ifndef COMPILER_CORE_LOGGER_H
#define COMPILER_CORE_LOGGER_H
#include "absl/status/status.h"
#include <source_location>
#include <string>
#include <string_view>

namespace compiler::core {
class Logger final {
  public:
    Logger() = delete;
    Logger(Logger &&) = delete;
    Logger &operator=(Logger &&) = delete;
    Logger(const Logger &) = delete;
    Logger &operator=(const Logger &) = delete;
    ~Logger() = delete;

    static void logInfo(std::string_view message);
    static void logInfo(std::string &&message);
    static void logError(std::string &&message,
                         std::source_location sourceLocation = {});
    static void logError(std::string_view message,
                         std::source_location sourceLocation = {});
    static void logError(const absl::Status &status,
                         std::source_location sourceLocation = {});

    [[noreturn]] static void
    logFatal(std::string &&message,
             std::source_location sourceLocation = {});
    [[noreturn]] static void
    logFatal(std::string_view message,
             std::source_location sourceLocation = {});
    [[noreturn]] static void
    logFatal(const absl::Status &status,
             std::source_location sourceLocation = {});

    [[nodiscard]] static std::string mergeMessageWithSourceLocation(
        std::string_view message,
        const std::source_location &sourceLocation);

    [[nodiscard]] static std::string sourceLocationToString(
        const std::source_location &sourceLocation);
};
} // namespace compiler::core
#endif // COMPILER_CORE_LOGGER_H
