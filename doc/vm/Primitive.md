# `Primitive`
## атомарные типы

### py

```py
## атомарные типы
class Primitive(Object): pass
```

```py
class Float(Primitive):
    def __init__(self, V):
        super().__init__(float(V))
```
![[vm/Int#py]]
![[vm/Sym#py]]

```py
## строка (заморачиваться с отдельными буквами нет смысла)
class String(Primitive): pass
```

[[vm/Container]]

### hpp

```Cpp
/// @defgroup prim primitive
/// @brief atomic types
/// @ingroup metal
/// @{

struct Primitive : Object {
    Primitive();
    Primitive(string value);
};
```
![[vm/Sym#hpp]]
![[vm/Int#hpp]]
```Cpp
/// @}
```
