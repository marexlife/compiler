#include "Logger.h"
#include "spdlog/spdlog.h"

namespace compiler::core {
void Logger::logError(absl::Status error) {
    spdlog::error(error.message());
}

void Logger::logFatal(absl::Status error) {
    Logger::logError(error);

    std::exit(-1);
}
} // namespace compiler::core
