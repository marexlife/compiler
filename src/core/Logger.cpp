#include "Logger.h"

#include <exception>
#include <iostream>
#include <print>
#include <string>

#include "ErrorFormatter.h"

namespace marex::core {
void Logger::flush() { std::cout.flush(); }

void Logger::log_info(std::string&& message) {
    if (log_infos) {
        std::println("info: {}", message);
    }
}

void Logger::log_error(
    std::string&& message,
    std::source_location source_location) {
    std::string format_result = ErrorFormater::
        merge_message_with_source_location(
            message, source_location);

    std::println("error: {}", format_result);
}

void Logger::log_fatal_error(
    std::string&& message,
    std::source_location source_location) {
    Logger::log_error(std::move(message),
                      source_location);
    throw std::exception();
}

void Logger::log_fatal_internal_error(
    std::string&& message,
    std::source_location source_location) {
    std::string format_result = ErrorFormater::
        merge_message_with_source_location(
            message, source_location);

    std::println("Internal error: {}", format_result);

    throw std::exception();
}
}  // namespace marex::core
