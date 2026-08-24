# operator

## `__iter__`
### `iter(A)`
```py
	## iter(A)
    def __iter__(self): return iter(self.nest)
```

## `__floordiv__`
### `A // B`

```py
	## A // B
    def __floordiv__(self, that):
        self.nest.append(self.box(that)); return self
```

## 

```py
	## if A
	def __bool__(self): return bool(self.nest)
```

## `__getitem__`
### `A[key]`

```py
	## A[key]
	def __getitem__(self, key):
        if isinstance(key, int): return self.nest[key]
		if isinstance(key, str): return self.slot[key]
        raise TypeError(['__getitem__', type(key), key])
```

## `ins`
### `A.ins(idx,B)`

```py
	## A.ins(idx,B)
	def ins(self, idx, that):
        self.nest.insert(idx, self.box(that))
```

### hpp

```Cpp
    /// @name operator

    Object* set(string key, Object* o);     ///< slot setter
    Object* get(string key);                ///< slot getter
    Object* operator[](const string& key);  ///< `A[key]`
    Object* push(Object* o);                ///< push as stack
    Object* pop();                          ///< pop as stack
```

### cpp

```Cpp
Object* Object::get(std::string key) {  //
    return slot[key];
}
```
```Cpp
Object* Object::set(std::string key, Object* o) {
    slot[key] = o;
    return this;
}
```
```Cpp
Object* Object::push(Object* o) {
    nest.push_back(o);
    return this;
}
```
```Cpp
Object* Object::pop() {
    assert(!nest.empty());
    Object* ret = nest.back();
    nest.pop_back();
    return ret;
}
```
