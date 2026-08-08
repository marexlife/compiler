#pragma once

#include <cstdint>

enum class [[nodiscard]] LastCharKind : std::uint8_t 
{
  None,
  WasDefault,
  WasNotDefault,
};
