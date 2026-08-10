#include "Logger.h"
#include "spdlog/spdlog.h"
#include <cstdlib>
#include <string>

namespace compiler::core {
void Logger::logFatal(std::string &&message) {
    spdlog::error(message);

    std::exit(-1);
}

void Logger::logError(std::string &&message) {
    spdlog::error(message);
}

void Logger::logError(std::string_view message) {
    spdlog::error(message);
}

void Logger::logFatal(std::string_view message) {
    spdlog::error(message);

    std::exit(-1);
}

void Logger::logError(absl::Status error) {
    spdlog::error(error.message());
}

void Logger::logFatal(absl::Status error) {
    Logger::logError(error);

    std::exit(-1);
}
} // namespace compiler::core
