#ifndef COMPILER_CORE_LOGGER_H_
#define COMPILER_CORE_LOGGER_H_
#include <spdlog/spdlog.h>

namespace compiler::core {
template <typename... Ts>
concept InfoLoggable = requires(Ts... ts) { spdlog::info(ts...); };

template <typename... Ts>
concept ErrorLoggable = requires(Ts... ts) { spdlog::error(ts...); };

class Logger final {
 public:
  Logger() = delete;

  static void LogInfo(InfoLoggable auto message) {
    spdlog::info(message);
  }

  static void LogError(InfoLoggable auto message) {
    spdlog::error(message);
  }
};
}  // namespace compiler::core
#endif  // COMPILER_CORE_LOGGER_H_
