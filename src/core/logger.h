#ifndef COMPILER_CORE_LOGGER_H_
#define COMPILER_CORE_LOGGER_H_
#include <iostream>
#include <string>
#include <string_view>
#include <type_traits>

namespace compiler::core {
template <typename T>
concept StringLike = std::is_same_v<T, std::string> ||
                     std::is_same_v<T, std::string_view>;

class Logger final {
 public:
  Logger() = delete;

  static void LogInfo(StringLike auto message) {
    std::operator<<(
        std::operator<<(std::operator<<(std::cout, "Info: "),
                        message),
        '\n');
  }

  static void LogError(StringLike auto message) {
    std::operator<<(
        std::operator<<(std::operator<<(std::cout, "Error: "),
                        message),
        '\n');
  }
};
}  // namespace compiler::core
#endif  // COMPILER_CORE_LOGGER_H_
