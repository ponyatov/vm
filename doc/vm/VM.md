# VM: Virtual Machine
## [[виртуальная машина]]


## [[virtualization]]
- [[hypervizor]]
- [[KVM]]
- [[vm/VMWare|VMWare]]

## [[языковая виртуальная машина]]
- [[JVM]]
- [[bytecode]]
- [[bcx]]
### [[Object Virtual Machine]]
### [[object graph]]
### [[metaL]]
- [[VM/pvm]]
- [[luna]]
- [[WI/WI|Writing Interpreters in Rust: a Guide]]

### hpp

[[vm/main]]

```Cpp
/// @brief Virtual Machine
struct VM : Active {
    VM(string value);
};
```
```Cpp
/// @brief root @ref VM runs on system init
extern VM vm;
```

### cpp

```Cpp
VM::VM(string value) : Active(value) {}

VM vm("FORTH");
```

```py
## Virtual Machine (isolated process)
class VM(Active): pass
```

[[metaL/VM|VM]] represents both
- isolated process
- execution context

which has internal [[FORTH]]-like structure:
- [[FORTH/vocabulary]]: symbolic names linked with some objects can 

## [[OCaml/CAM]]
## [[vm/ZAM]]