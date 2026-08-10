#include "Logger.h"
#include "spdlog/spdlog.h"
#include <format>

namespace compiler::core {
void Logger::log(absl::Status error)
{
    const auto formatedMesaage = std::format("{}", error.message());

    spdlog::error(formatedMesaage);
}
}
