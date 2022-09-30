# Object Graph

* groups of objects
* form a network through their 
* relationships with each other (via pointers)

Having in mind
* modern OOP programming languages design (C++, Python, JS,..)
* [attribute grammar](https://en.wikipedia.org/wiki/Attribute_grammar) for any
  source code representation and metaprogramming
* Marvin Minsky's
  [frames](https://web.media.mit.edu/~minsky/papers/Frames/frames.html) as a
  generic form of
  [KR&R](https://en.wikipedia.org/wiki/Knowledge_representation_and_reasoning)

we can consider some base @ref Object class as a root building block for holding
both data and program representation in a homoiconic manner (executable data,
a.k.a **Executable Data Structure** (c).

In contrast to the UML class diagram details the relationships between classes,
the object graph relates their instances.

## Database

As we can allocate object graph in persistent memory, we can treat it as an
object graph database and general-purpose programming system at a same time.
Such **persistent virtual memory** is a powerful thing -- NVRAM is the best
hardware approach (such as Intel Optane NVDIMMs), but also it can be emulated
with `mmap()` runs on any mainstream computer system.
