# [[vm/VM|VM]] files

```
lib/vm
├── inc
│   ├── command.hpp          # VM commands
│   ├── compiler.hpp
│   ├── config.hpp
│   ├── debug.hpp
│   ├── memory.hpp
│   ├── pmem.hpp
│   ├── repl.hpp
│   ├── syntax.hpp
│   ├── types.hpp
│   └── vm.hpp
└── src
    ├── command.cpp          # VM commands code
    ├── compiler.cpp         # compiler
    ├── debug.cpp            # debug tooling
    ├── memory.cpp           # VM memory
    ├── pmem.cpp             # paged memory
    ├── syntax.cpp
    ├── vm.cpp
    ├── vm.lex               # lexer
    └── vm.yacc              # syntax parser
```
