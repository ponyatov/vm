/// @defgroup vm vm
/// @brief bytecode virtual machine (embedded language script engine)
/// @ingroup lib
/// @{
#pragma once

#include "memory.hpp"
#include "debug.hpp"
#include "command.hpp"

/// @brief run compiled bytecode
/// @returns int for fake @ref main () return
extern int vm();

/// @}
