#ifndef MAREX_CORE_LOGGER_H
#define MAREX_CORE_LOGGER_H
#include <source_location>
#include <string_view>

namespace marex::core {
class Logger final {
  public:
    Logger() = delete;
    Logger(Logger &&) = delete;
    Logger &operator=(Logger &&) = delete;
    Logger(const Logger &) = delete;
    Logger &operator=(const Logger &) = delete;
    ~Logger() = delete;

    static void logInfo(std::string_view message);
    static void logError(std::string_view message,
                         std::source_location sourceLocation =
                             std::source_location::current());

    [[noreturn]] static void
    logFatalError(std::string_view message,
                  std::source_location sourceLocation =
                      std::source_location::current());

    [[noreturn]] static void
    logFatalInternalError(std::string_view message,
                          std::source_location sourceLocation =
                              std::source_location::current());
};
} // namespace marex::core
#endif // MAREX_CORE_LOGGER_H
