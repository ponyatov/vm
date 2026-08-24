# lib/vm/src/memory.cpp

```cpp
#include "memory.hpp"

byte M[Msz];

addr Cp = 0;
addr Ip = 0;

addr R[Rsz];
uint8_t Rp = 0;

cell D[Dsz];
uint8_t Dp = 0;
```
- [[vm/M|M]]
	- [[vm/Cp|Cp]]
	- [[vm/Ip|Ip]]
- [[vm/R|R]]
	- [[Rp]]
- [[vm/D|D]]
	- [[Dp]]
