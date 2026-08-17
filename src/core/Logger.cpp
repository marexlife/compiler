#include "Logger.h"
#include "ErorrFormater.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <string_view>

namespace marex::core {
void Logger::logInfo(std::string_view message) {
    std::cout << "info: " << message << '\n';
}

void Logger::logError(std::string_view message,
                      std::source_location sourceLocation) {
    std::string formatResult =
        ErrorFromater::mergeMessageWithSourceLocation(message,
                                                      sourceLocation);

    std::cout << "error: " << formatResult << '\n';
}

void Logger::LogFatalError(std::string_view message,
                           std::source_location sourceLocation) {
    Logger::logError(message, sourceLocation);

    std::exit(-1);
}

void Logger::LogFatalInternalError(
    std::string_view message, std::source_location sourceLocation) {
    std::string formatResult =
        ErrorFromater::mergeMessageWithSourceLocation(message,
                                                      sourceLocation);

    std::cout << "Internal error: " << formatResult << '\n';

    std::exit(-1);
}
} // namespace marex::core
