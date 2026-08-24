# VAT
## [[vm/thread|thread]] group container

[[VAT]] thread container is an abstraction that groups and manages a collection of [[vm/thread|threads]], often to treat them as a single logical unit for resource management, monitoring, and lifecycle control

- one [[vm/M|M]] memory area shared for all [[vm/thread|threads]] in a group
- [[vm/gc#principles|garbage collector]] allocates heap in a VAT memory
