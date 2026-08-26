# `μ` embedded language

(c) [[Dmitry Ponyatov]] <<dponyatov@gmail.com>> 2025 [[license/MIT|MIT]]

- bytecode/stack VM
	- [[compiler/AOT|AOT]] bytecode compiler
		- MCU-enabled ([[esp/ESP32|ESP32]], [[em/Cortex-M|Cortex-M]])
	- desktop/server host OSes ([[Linux/Linux|Linux]], [[Windows]], [[macOS]]?)
		- embedded Linux (RPi, PC104, retro devices)
- micro/embedded script engine
	- [[FORTH/FORTH|FORTH]]-inspired on-device [[lang/REPL|REPL]] (<64K SRAM)
- tiny portable [[git/gui|GUI]] ([[SDL/SDL|SDL]]-based, no host OS integration)
	- HMI (multimedia & IIoT, industrial control panels, SmartHome, CarPC,..)
- maybe...
	- WASM-based VM port to move parts of the virtualized infrastructure into the end-user browser to allow for low-latency and offline use cases

## Core Architecture Components

- [[vm/vm|The Shared Runtime]]
	- A single native process (or tiny bare-metal kernel) running on each physical node. It manages raw memory, network sockets, and I/O routing without a traditional hypervisor layer.
- Software-Isolated Processes
	- Instead of VMs or containers, nodes in the virtual cluster are isolated code/memory spaces running within the runtime. Memory safety is strictly enforced by the bytecode isolation, meaning code cannot break out of its sandbox or access other tenants' data.
- Virtual Control Plane
	- An abstraction layer that makes these distributed bytecode runners look and behave like a multi-node cluster, scheduling workloads and routing cross-interpreter traffic.

![[vm/approaches]]

## Trade-offs

- *Pros*
	- **low memory footprints**
		- *allows to use MCU nodes*
		- stack VM with single-byte commands has the most compact compiled code (comparing to RISC-like or register-based command sets)
		-  extreme density
			- thousands of virtual nodes on a single host
			- millisecond node startup times
	- **absolute platform portability**
		- very fast VM porting to any new architecture or host OS
	- unlimited debug capabilities
- *Cons*
	- bound to the specific language and bytecode ecosystem
		- **need special compiler** (maybe multiple language frontends)
	- lacks raw access to low-level hardware
		- need some hw access gateways or special raw I/O commands
