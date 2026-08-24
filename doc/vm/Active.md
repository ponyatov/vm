# `Active`
## Executable Data Structure (c)

### py

```py
## исполняемая структура данных (c)
class Active(Object): pass
```

```py
## оператор
class Op(Active): pass

class Div(Op): pass
```

```py
## виртуальная Форт-машина
class VM(Active): pass
```

```py
## команда виртуальной машины
class Cmd(Active): pass
```

```py
## функция
class Fn(Active): pass
```

### hpp

```Cpp
/// @defgroup active active
/// @brief Executable Data Structure (c)
/// @ingroup metal
/// @{

struct Active : Object {
    Active(string value);
};
```
![[vm/vm#hpp]]
```Cpp
/// @}
```

### cpp

```Cpp
Active::Active(string value) : Object(value) {}
```
![[vm/vm#cpp]]
