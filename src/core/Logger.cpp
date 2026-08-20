#include "Logger.h"
#include "ErorrFormater.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <string_view>

namespace marex::core {
void Logger::log_info(std::string_view message) {
    std::cout << "info: " << message << '\n';
}

void Logger::log_error(std::string_view message,
                       std::source_location sourceLocation) {
    std::string formatResult =
        ErrorFormater::merge_message_with_source_location(
            message, sourceLocation);

    std::cout << "error: " << formatResult << '\n';
}

void Logger::log_fatal_error(std::string_view message,
                             std::source_location sourceLocation) {
    Logger::log_error(message, sourceLocation);

    std::exit(-1);
}

void Logger::log_fatal_internal_error(
    std::string_view message, std::source_location sourceLocation) {
    std::string formatResult =
        ErrorFormater::merge_message_with_source_location(
            message, sourceLocation);

    std::cout << "Internal error: " << formatResult << '\n';

    std::exit(-1);
}
} // namespace marex::core
