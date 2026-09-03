#ifndef MAREX_CORE_LOGGER_H
#define MAREX_CORE_LOGGER_H
#include <cstdint>
#include <source_location>
#include <string>
#include <utility>

namespace marex::core {
enum struct [[nodiscard]] LogLevelKind : std::uint8_t {
    None = 0,
    InternalError,
    FatalError,
    Error,
    Info,
};

class Logger final {
   public:
    Logger() = delete;
    Logger(Logger&&) = delete;
    Logger& operator=(Logger&&) = delete;
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    ~Logger() = delete;

    static void flush();

    static void log_info(std::string&& message);

    static consteval bool is_minimum_at_log_level(
        LogLevelKind minimum) {
        return std::to_underlying(log_level_kind) >=
               std::to_underlying(minimum);
    }

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

   private:
    static const LogLevelKind log_level_kind =
        LogLevelKind::Info;
};
}  // namespace marex::core
#endif  // MAREX_CORE_LOGGER_H
