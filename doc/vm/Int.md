### py

```py
class Int(Primitive):
    def __init__(self, V):
        super().__init__(int(V))
```

### hpp

```Cpp
/// @brief integer number
struct Int : Primitive {
    int value;
    Int(int value);
    string val();
};
```

### cpp

```Cpp
Int::Int(int value) : Primitive() { this->value = value; }
```
```Cpp
string Int::val() { return to_string(value); }
```
