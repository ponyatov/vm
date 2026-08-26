# [[vm/vm|vm]] memory

The [[vm/vm|vm]] uses a memory model with separate fixed-size regions for code/data, and multiple stacks:

```cpp
extern byte M[Msz];  ///< main memory
extern addr Cp;      ///< compiler pointer
extern addr Ip;      ///< instruction pointer

extern addr R[Rsz];  ///< return stack
extern byte Rp;      ///< @ref R pointer

extern cell D[Dsz];  ///< data stack
extern byte Dp;      ///< @ref D pointer
```

## [[vm/pmem|paged memory]]
