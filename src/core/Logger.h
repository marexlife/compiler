#ifndef MAREX_CORE_LOGGER_H
#define MAREX_CORE_LOGGER_H
#include <source_location>
#include <string>

namespace marex::core {
class Logger final {
   public:
    Logger() = delete;
    Logger(Logger&&) = delete;
    Logger& operator=(Logger&&) = delete;
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    ~Logger() = delete;

    static void log_info(std::string&& message);

    static void log_error(
        std::string&& message,
        std::source_location source_location =
            std::source_location::current());

    [[noreturn]] static void log_fatal_error(
        std::string&& message,
        std::source_location source_location =
            std::source_location::current());

    [[noreturn]] static void log_fatal_internal_error(
        std::string&& message,
        std::source_location source_location =
            std::source_location::current());
};
}  // namespace marex::core
#endif  // MAREX_CORE_LOGGER_H
