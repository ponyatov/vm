/// @defgroup compiler compiler
/// @brief bytecode compiler
/// @ingroup vm
/// @{
#pragma once

#include "lib.hpp"
#include "vm.hpp"

extern std::map<std::string, addr> label;  ///< known labels

extern addr compile(byte b);  ///< compile single byte
/// @}
