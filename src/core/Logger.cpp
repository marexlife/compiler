#include "Logger.h"

#include <cstdlib>
#include <iostream>
#include <print>
#include <string>

#include "ErrorFormatter.h"

namespace marex::core {
void Logger::flush() { std::cout.flush(); }

void Logger::log_info(std::string&& message) {
    std::println("info: {}", message);
}

void Logger::log_error(
    std::string&& message,
    std::source_location source_location) {
    std::string format_result = ErrorFormater::
        merge_message_with_source_location(
            message, source_location);

    if (is_minimum_at_log_level(LogLevelKind::Error)) {
        std::println("error: {}", format_result);
    }
}

void Logger::log_fatal_error(
    std::string&& message,
    std::source_location source_location) {
    if (is_minimum_at_log_level(
            LogLevelKind::FatalError)) {
        Logger::log_error(std::move(message),
                          source_location);
    }

    std::exit(-1);
}

void Logger::log_fatal_internal_error(
    std::string&& message,
    std::source_location source_location) {
    std::string format_result = ErrorFormater::
        merge_message_with_source_location(
            message, source_location);

    if (is_minimum_at_log_level(
            LogLevelKind::InternalError)) {
        std::println("Internal error: {}",
                     format_result);
    }

    std::exit(-1);
}
}  // namespace marex::core
