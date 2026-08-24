/// @defgroup command command
/// @brief @ref vm commands
/// @ingroup vm
/// @{
#pragma once

#include "lib.hpp"

enum class Op : uint8_t {
    nop = 0x00,
    halt = 0xFF,
    dump = 0xDD,
    call = 0x01,
    ret = 0x02,
    jmp = 0x03,
};

extern void nop();   ///< `( -- )` do nothing (empty command)
extern void halt();  ///< `( -- )` stop the whole @ref vm
extern void dump();  ///< `( -- )` dump @ref vm state
extern void call();  ///< `(R: -- addr)` nested call
extern void ret();   ///< `(R: addr -- )` return from @ref call
extern void jmp();   ///< `( -- )` unconditional jump

/// @}
