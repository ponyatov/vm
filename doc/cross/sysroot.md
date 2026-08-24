# sysroot

In cross-compilation, a `sysroot` is a directory on your development host that acts as a stand-in for the root directory (`/`) of your target system: contains all the system-level resources the compiler needs: header files, libraries, and sometimes even configuration files and binaries.

The core problem with cross-compilation is that the development host and the target device are fundamentally different. They have different architectures (e.g., x86_64 vs. ARM) and different system resources.

Some targets totally has no concept of file system, so cross-compiler must have some directory on host system that contains all compiler-specific files, some libraries such as libgcc, libc etc.

The compiler and linker on the host system need to find:

- Header files (`stdio.h`, `stdint.h`, `stdlib.h`)
- precompiled Libraries (`libc.a`, `libm.a`, `libgcc.a`)
- Startup files (`crt0.o`, `crti.o`)
- Linker scripts (memory layout definitions)

Also you may want to add some side libraries and use them on target system:
- **zlib** (compression)

```
# ~/project/cross/sysroot/
# (or ~/project/root in case of embedded Linux)

sysroot/
├── usr/
│   ├── include/
│   │   ├── stdio.h       ← ARM version
│   │   ├── stdint.h      ← ARM version
│   │   └── stdlib.h      ← ARM version
│   └── lib/
│       ├── libc.a        ← ARM version (static library)
│       └── libm.a        ← ARM version
└── lib/
    ├── crt0.o            ← ARM startup code
    ├── libgcc.a          ← ARM compiler runtime
    └── stm32f4.ld        ← ARM memory layout
```

## libgcc

**ibgcc.a** provides low-level compiler helper functions:

- 64-bit division on 32-bit CPUs
- Multiplication overflow handling
- Exception handling support
- Stack unwinding
- Software floating-point emulation
