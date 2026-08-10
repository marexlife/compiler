#ifndef COMPILER_CORE_LOGGER_H
#define COMPILER_CORE_LOGGER_H
#include "absl/status/status.h"
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
    static void logError(std::string &&message);
    static void logError(std::string_view message);
    static void logError(absl::Status error);
    [[noreturn]] static void logFatal(std::string &&message);
    [[noreturn]] static void logFatal(std::string_view message);
    [[noreturn]] static void logFatal(absl::Status error);
};
} // namespace compiler::core
#endif // COMPILER_CORE_LOGGER_H
