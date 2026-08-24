```rust
/// 0xFF `( -- )` stop system
fn halt() -> ! {
    std::process::exit(0);
}
```

## no_std

```rust
#![no_std]
use cortex_m_semihosting::debug;

pub fn halt() -> ! {
    debug::exit(debug::EXIT_SUCCESS);
    loop {}
}
```
- [[Rust/Debug#exit]]
- [[Rust/Debug#EXIT_SUCCESS]]
- [[cortex_m_semihosting#debug]]
