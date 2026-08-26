## Similar approaches

- Inferno OS (Dis/Limbo)

- [[Erlang]] [[BEAM]] Virtual Machine
	- The gold standard for this architecture. The BEAM interpreter manages its own lightweight, independent processes, scheduling, garbage collection, and clustering natively over the network. It handles millions of virtual "nodes" with zero hardware virtualization.

- [[WebAssembly]] (Wasm) Clusters & [[WASI]]:
	- Modern decentralized micro-runtimes (like [[wasmtime]] or [[WAMR]]) use WebAssembly bytecode to build dense clusters. Frameworks like Fermyon Spin or [[Lunatic]] deploy hundreds of isolated Wasm instances across network nodes, treating the bytecode actors as a highly dense, hyper-scalable cluster.
		- [[Lunatic]] with [[people/Bernard Kolobara]]

- [[Java/Java|Java]] Virtual Machine ([[Java/JVM|JVM]]) Grid & Cluster Frameworks:
	- Ecosystems like Apache Ignite or Hazelcast build a virtualized distributed cluster directly on top of the JVM interpreter layer, clustering bytecode data objects and computing tasks seamlessly.

- Singularity (Historical Research OS)
	- A [[Microsoft Research]] operating system that replaced hardware-based page tables with software-isolated processes running type-safe MSIL bytecode.
