# stack-based virtual machine

Next, there’s the phrase stack-based virtual machine. We’ll go over this in detail soon, but the short explanation is that this stack machine simultaneously contributes to [[WebAssembly]]’s tremendous speed, power, and several of its limitations.

### hpp

```cpp
/// @brief FIFO
struct Stack : Container {};
```

### cpp

```cpp
Stack::Stack(string value) : Container(value) {}
```

- [[stack machine]]
- [[Stack Machines]]

## push
`( -- a )`
adding data to top of stack

## pop
`( a -- )`
getting from top

## top
`( a -- )`
getting copy from top without removing
