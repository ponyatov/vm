# bytecode
## Why custom VM is Essential for This Application?

The custom bytecode approach is a necessary and strategically sound solution for this project, but it is not without significant technical hurdles. The choice is justified by the project's core requirements:
- [[#resource-constrained hardware]]
- the need for [[#platform independence]]
- and a distributed, high-level [[#actor model]].

## resource-constrained hardware

- some nodes has less then 20K SRAM
	- You cannot run a generic JavaScript or Python interpreters, as you has no memory even for intensive heap usage
- some components require hard-realtime control
	- this code can't be implemented with dynamic memory overhead and garbage collection pauses, so it must be written in highly-optimized native code (C/C++ fragments)
- any device runs your code doesn't need a compiler; it just needs your own few Kb VM interpreter loop, and some memory for internal and application data

## platform independence

- Compiling C++ natively for the every architecture requires maintaining many different toolchains, binary blobs, and test benches with hardware components involved
- **The Solution:** The VM is written once in portable C (or even assembly) for the every CPU/hardware. Your application logic is written in a high-level scripts and compiled to your **low-weight bytecode**.
- Even running bytecode instance can be serialized and moved into other node
- VM code is simple and small enough to be ported to a new system/platform in a few days

## actor model

Actors send asynchronous messages. If you used native code, each message type would require a hardcoded function pointer and a table or giant `switch` statement for handler selection, that grows with each new actor type.

- **Bytecode as a Mailbox Handler:** Your VM treats incoming messages as **continuations** runs in a short-leaving isolated process instances. Any context and allocated memory is local for the single actor's mailbox handler call.

- **Scratch Memory**. When a message arrives, the VM starts isolated actor's instance, executes exactly the bytecode sequence needed to handle that message, and clean-up the whole state and memory with a single `dealloc`. All the used memory is located in a tiny single-thread process, GC can run fast or ever not used any time until the message processing finishes.

- **Serialization:** Bytecode is inherently linear. You can serialize an actor's entire state (stack + memory + registers) into a flat few Kb payload and send it over RF or network to another node. The receiving node loads it into its VM and resumes execution exactly where the sender left off — something nearly impossible to do safely with native ARM/AVR binary code.

## intellectual property

- bytecode compiles on development station and transfers into node it must run it
- there is no source code leaks for commercial apps: compiled bytecode too low-level to make it easy for reverse engineering
- you use use own memory layout, command system and formats, so nobody else has some tools to dig into it
- you use your own VM so has no any problems with patented formats, command sets, etc; there are no any licenses/patent encumbrances.

## infinite flexibility

- you can choose your own VM architecture, command set, memory management and scheduling algorithms
- **bytecode interpretation is fantastic for adding your own debug jigs**, there is no limits with breakpoints, and any complex watches can be written in C++ and integrated into interpreter loop
- if you need real fast or resource-effective code, you can write it in native C(++) and integrate it as custom (atomic) commands
