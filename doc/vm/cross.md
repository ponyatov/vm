# cross
## embedded C++ toolchain

## source

```
hw/
	pc/
		inc/
			pc.hpp
cpu/
	i5/
		inc/
			i5.hpp
	i486/
		inc/
			i486.hpp
arch/
	x86_64/
		inc/
			x86_64.hpp
	i386/
		inc/
			i386.hpp
os/
	linux/
		inc/
			linux.hpp       # Server/Desktop/Embedded Linux
lib/
	inc/
		lib.hpp             # shared source code libs for cross projects
		posix.hpp           # POSIX-compatible envs
	vm/                     # bytecode compiler/interpreter
```

## cmake

```
CMakePresets.json
CMakeLists.txt
cmake/
	
```
