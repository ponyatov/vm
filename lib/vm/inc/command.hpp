/// @defgroup command command
/// @brief @ref vm commands
/// @ingroup vm
/// @{
#pragma once

#include "lib.hpp"

enum class Op : uint8_t {  //
    nop = 0x00,
    halt = 0xFF,
    debug = 0xDE,
};

/// @}
