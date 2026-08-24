/// @defgroup types types
/// @brief embedded @ref vm specific types\e
/// @ingroup vm
/// @{
#pragma once
#include "stdint.h"

/// single byte
typedef uint8_t byte;

/// @ref M address (limited less then 64K)
typedef uint16_t addr;

/// @ref D signed integer (32-bit as most universal)
typedef int32_t cell;

/// @}
