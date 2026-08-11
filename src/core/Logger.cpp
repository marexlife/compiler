#include "Logger.h"
#include "ErorrFormater.h"
#include "spdlog/spdlog.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <string_view>

namespace marex::core {
void Logger::logInfo(std::string_view message) {
    spdlog::info(message);
}

void Logger::logError(std::string_view message,
                      std::source_location sourceLocation) {
    std::string formatResult =
        ErrorFromater::mergeMessageWithSourceLocation(message,
                                                      sourceLocation);

    spdlog::error(message);
}

void Logger::logFatalError(std::string_view message,
                           std::source_location sourceLocation) {
    Logger::logError(message, sourceLocation);

    std::exit(-1);
}

void Logger::logFatalInternalError(
    std::string_view message, std::source_location sourceLocation) {
    std::cout << "Internal error:";
    Logger::logFatalError(message, sourceLocation);
}
} // namespace marex::core
