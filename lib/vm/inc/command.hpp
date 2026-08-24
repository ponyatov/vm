/// @defgroup command command
/// @brief @ref vm commands
/// @ingroup vm
/// @{
#pragma once

#include "lib.hpp"

enum class Op : uint8_t {
    nop = 0x00,
    halt = 0xFF,
    debug = 0xDE,
};

extern void nop();    ///< `( -- )` do nothing (empty command)
extern void halt();   ///< `( -- )` stop the whole @ref vm
extern void debug();  ///< `( -- )` dump @ref vm state

/// @}
