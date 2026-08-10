#include "Logger.h"
#include "spdlog/spdlog.h"

namespace compiler::core {
void Logger::log(absl::Status error)
{
    spdlog::error(error.message());
}
}
