#ifndef COMPILER_CORE_LOGGER_H
#define COMPILER_CORE_LOGGER_H
#include "absl/status/status.h"

namespace compiler::core {
class Logger final {
public:
    Logger() = delete;
    Logger(Logger&&) = delete;
    Logger& operator=(Logger&&) = delete;
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    ~Logger() = delete;

    static void log(absl::Status error);
};
}
#endif // COMPILER_CORE_LOGGER_H
