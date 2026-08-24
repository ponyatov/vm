![[Cpp/init|init]]

### cpp

```cpp
#include "main.hpp"
```

![[Cpp/fini]]

```cpp
void init(int& argc, char* argv[]) {
    arg(0, argv[0]);
    // argc
    auto c = new Int(argc);
    vm.set("argc", c);
    // argv
    Vector* v = new Vector("argv");
    vm.set("argv", v);
    for (int i = 0; i < argc; i++) v->push(new Str(argv[i]));
    // gui
    vm.set("gui", new Cmd(gui));
    // dump vm
    cout << vm.dump() << endl << endl;
}
```
