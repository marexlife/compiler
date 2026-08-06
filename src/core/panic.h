#ifndef COMPILER_CORE_PANIC_H_
#define COMPILER_CORE_PANIC_H_
#include <source_location>
#include <string_view>

namespace compiler::core {
void Panic(std::string_view message,
           std::source_location source_location = {});

std::string SourceLocationAsString(
    std::source_location source_location = {});
}  // namespace compiler::core
#endif  // COMPILER_CORE_PANIC_H_
