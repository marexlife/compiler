#include "Logger.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>

#include "ErorrFormater.h"

namespace marex::core {
void Logger::flush() { std::cout.flush(); }

void Logger::log_info(std::string&& message) {
    std::cout << "info: " << message << '\n';
}

void Logger::log_error(
    std::string&& message,
    std::source_location source_location) {
    std::string format_result = ErrorFormater::
        merge_message_with_source_location(
            message, source_location);

    std::cout << "error: " << format_result << '\n';
}

void Logger::log_fatal_error(
    std::string&& message,
    std::source_location source_location) {
    Logger::log_error(std::move(message),
                      source_location);

    std::exit(-1);
}

void Logger::log_fatal_internal_error(
    std::string&& message,
    std::source_location source_location) {
    std::string formatResult = ErrorFormater::
        merge_message_with_source_location(
            message, source_location);

    std::cout << "Internal error: " << formatResult
              << '\n';

    std::exit(-1);
}
}  // namespace marex::core
