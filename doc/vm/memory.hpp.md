# lib/vm/inc/memory.hpp

```cpp
/// @defgroup memory memory
/// @brief @ref vm memory
/// @ingroup vm
/// @{

#include "config.hpp"
#include "types.hpp"

extern byte M[Msz];  ///< main memory
extern addr Cp;      ///< compiler pointer
extern addr Ip;      ///< instruction pointer

extern addr R[Rsz];  ///< return stack
extern uint8_t Rp;   ///< @ref R pointer

extern cell D[Dsz];  ///< data stack
extern uint8_t Dp;   ///< @ref D pointer

/// @}
```

![[vm/registers]]

