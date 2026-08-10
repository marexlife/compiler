#include "Logger.h"
#include "spdlog/spdlog.h"
#include <cstdlib>
#include <format>
#include <string>
#include <string_view>

namespace compiler::core {
void Logger::logInfo(std::string &&message) { spdlog::info(message); }

void Logger::logInfo(std::string_view message) {
    spdlog::info(message);
}

void Logger::logError(std::string &&message,
                      std::source_location sourceLocation) {
    Logger::logError(message, sourceLocation);
}

void Logger::logError(std::string_view message,
                      std::source_location sourceLocation) {
    std::string formatResult =
        mergeMessageWithSourceLocation(message, sourceLocation);

    spdlog::error(message);
}

void Logger::logError(const absl::Status &status,
                      std::source_location sourceLocation) {
    Logger::logError(status.message(), sourceLocation);
}

void Logger::logFatal(std::string &&message,
                      std::source_location sourceLocation) {
    Logger::logError(message, sourceLocation);

    std::exit(-1);
}

void Logger::logFatal(std::string_view message,
                      std::source_location sourceLocation) {
    Logger::logError(message, sourceLocation);

    std::exit(-1);
}

void Logger::logFatal(const absl::Status &status,
                      std::source_location sourceLocation) {
    Logger::logError(status, sourceLocation);

    std::exit(-1);
}

std::string Logger::mergeMessageWithSourceLocation(
    std::string_view message,
    const std::source_location &sourceLocation) {
    return std::format(
        "{}\n{}", message,
        Logger::sourceLocationToString(sourceLocation));
}

std::string Logger::sourceLocationToString(
    const std::source_location &sourceLocation) {
    return std::format(
        "at: {}, {}, {}:{}", sourceLocation.file_name(),
        sourceLocation.function_name(), sourceLocation.line(),
        sourceLocation.column());
}
} // namespace compiler::core
