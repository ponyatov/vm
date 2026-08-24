## `tag`

```py
	def tag(self): return self.type
```

## `val`

```py
    def val(self): return f'{self.value}'
```

![[metaL/format]]

### hpp

```Cpp
    /// @name dump/stringify

    virtual string tag();             ///< object class/type tag
    virtual string val();             ///< object value
    string  pad(size_t depth);        ///< left padding for dumps
    string head(string prefix = "");  ///< `<T:V>` header
    string dump(size_t depth = 0,
                string prefix = "");  ///< full text tree dump
```

![[vm/tag]]
