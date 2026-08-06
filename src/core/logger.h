#ifndef COMPILER_CORE_LOGGER_H_
#define COMPILER_CORE_LOGGER_H_
#include <string>
#include <string_view>

namespace compiler::core {
class Logger final {
 public:
  Logger() = delete;

  static void LogInfo(std::string&& message);
  static void LogInfo(std::string_view message);
  static void LogError(std::string&& message);
  static void LogError(std::string_view message);
};
}  // namespace compiler::core
#endif  // COMPILER_CORE_LOGGER_H_
