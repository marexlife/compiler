#ifndef COMPILER_CORE_LOGGER_H_
#define COMPILER_CORE_LOGGER_H_
#include <string>

namespace compiler::core {
class Logger final {
 public:
  Logger() = delete;

  static void LogInfo(std::string&& message);
};
}  // namespace compiler::core
#endif  // COMPILER_CORE_LOGGER_H_
