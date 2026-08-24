/// @defgroup compiler compiler
/// @brief bytecode compiler
/// @ingroup vm
/// @{
#pragma once

#include "lib.hpp"
#include "vm.hpp"

extern std::map<std::string, addr> global;                ///< global labels
extern std::map<std::string, addr> local;                 ///< local labels
extern std::map<std::string, std::vector<addr>> forward;  ///< forward refs
extern std::map<addr, std::string> reverse;               ///< reverse resolve

extern addr compile(byte b);  ///< compile @ref byte
extern addr compile(addr a);  ///< compile @ref cell

extern addr label(std::string *s, bool glob);  ///< register label
extern addr resolve(std::string *s);  ///< get addr from @ref local / @ref label
extern std::string resolve(addr a);   ///< @ref reverse
/// @}
