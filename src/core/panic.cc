#include "panic.h"

#include <format>
#include <iostream>
#include <string>

namespace compiler {
void core::Panic(std::string_view message,
                 std::source_location source_location) {
  std::exit(-1);
}

std::string core::SourceLocationAsString(
    std::source_location source_location) {
  return std::format(
      R"(at file: '{}'
at function_name: '{}'
at line: '{}'
at column '{}'
)",
      source_location.file_name(), source_location.function_name(),
      source_location.line(), source_location.column());
}
}  // namespace compiler
