## `__init__`

```py
    ## @name constructor

    def __init__(self, V):
        self.type = self.__class__.__name__.lower()
        self.value = V
        self.slot = {}
        self.nest = []
```

## `box`

```py
    def box(self, that):
        if isinstance(that, Object): return that
        if isinstance(that, str): return S(that)
        raise TypeError(['box', type(that), that])
```

## C++

```Cpp
Object::Object(QString V) : value(V) {
  ref = 0;
  next = pool;
  pool = this;
}
```
Object::~Object() {}
```
