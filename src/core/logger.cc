#include "logger.h"

#include <iostream>
#include <string_view>

namespace compiler::core {
void Logger::LogInfo(std::string&& message) {
  std::cout << "Info: " << message << '\n';
}

void Logger::LogInfo(std::string_view message) {
  std::cout << "Info: " << message << '\n';
}

void Logger::LogError(std::string&& message) {
  std::cout << "Error: " << message << '\n';
}

void Logger::LogError(std::string_view message) {
  std::cout << "Error: " << message << '\n';
}
}  // namespace compiler::core
