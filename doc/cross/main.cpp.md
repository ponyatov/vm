# os/linux/src/main.cpp

```cpp
#include "posix.hpp"

__attribute__((weak)) int main(int argc, char *argv[]) {
    arg(0, argv[0]);
    for (int i = 1; i < argc; i++) {  //
        arg(i, argv[i]);
    }
    return 0;
}

__attribute__((weak)) void arg(int argc, char *argv) {  //
    fprintf(stderr, "%i: %s\n", argc, argv);
}
```
