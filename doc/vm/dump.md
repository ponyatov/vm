## `__repr__`

```py
    ## print() callback
    def __repr__(self): return self.dump()
```

## `dump`

```py
    ## full text tree dump
    def dump(self, cycle=[], depth=0, prefix=''):
        # head
        def pad(depth): return '\n' + '\t' * depth
        ret = pad(depth) + self.head(prefix)
        # cycle
        if not depth: cycle = []
        if self in cycle: return f'{ret} _/'
        else: cycle.append(self)
        # slot{}s
        for i in self.keys():
            ret += self[i].dump(cycle, depth + 1, f'{i} = ')
        # nest[]ed
        for j, k in enumerate(self):
            ret += k.dump(cycle, depth + 1, f'{j}: ')
        # subtree
        return ret
```

## `head`

```py
    ## <T:V> header
    def head(self, prefix=''):
        gid = f' @{id(self):x}'
        return f'{prefix}<{self.tag()}:{self.val()}>{gid}'
```

### cpp

[[vm/Object.hpp|Object.hpp]]
[[vm/stringify]]

```Cpp
string Object::dump(size_t depth, string prefix) {
    ostringstream ret;
    // head
    ret << pad(depth) << head(prefix);
    // slot{}s
    for (auto const& [k, v] : slot)  //
        ret << v->dump(depth + 1, k + " = ");
    // nesty[]ed
    int idx = 0;
    for (const auto& i : nest)  //
        ret << i->dump(depth + 1, to_string(idx++) + ": ");
    // subtree
    return ret.str();
}
```
