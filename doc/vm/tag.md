```cpp
#include <cxxabi.h>

std::string Object::tag() const {
    std::string ret =
        abi::__cxa_demangle(typeid(*this).name(), NULL, NULL, nullptr);
    for (char &c : ret) c = tolower(c);
    return ret;
}
```
