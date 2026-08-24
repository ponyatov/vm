# Op

```rust
/// VM commands opcodes
enum Op {
    // flow control
    /// [nop] `( -- )` empty command
    nop = 0x00,
    /// [halt] `( -- )` stop system
    halt = 0xFF,
    /// [jmp] `( -- )` unconditional jump
    jmp = 0x01,
    /// [qjmp] `( bool -- )` jump if `false`
    qjmp = 0x02,
    /// [call] `(R: -- addr )` nested call
    call = 0x03,
    /// [ret] `(R: addr -- )` return from nested call
    ret = 0x04,
    /// [lit] `( -- n )` integer literal
    lit = 0x05,
```

- [[vm/nop]]
- [[vm/halt]]
- [[vm/jmp]]
- [[vm/qjmp]]

## Display

```rust
// disassembler
impl fmt::Display for Op {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match *self {
            Op::nop  => write!(f, "nop" ),
            Op::halt => write!(f, "halt"),
            Op::jmp  => write!(f, "jmp" ),
            Op::qjmp => write!(f, "qjmp"),
            Op::call => write!(f, "call"),
            Op::ret  => write!(f, "ret" ),
            Op::lit  => write!(f, "lit" ),
            _ => write!(f, "???"),
        }
    }
}
```
