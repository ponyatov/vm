# [[metaL]] classes
#metaL 

```plantuml
!theme black-knight
class Object {
	Class tag
	String value
	Map slot
	Vector nest
	tag()
	value()
	gid()
	head(prefix)
	dump(depth,prefix)
}

Object o-- Map

class Primitive
Object <|-- Primitive
class String
Primitive <|-- String
class Number
class Integer
Primitive <|-- Number
Number <|-- Integer

class Container
Object <|-- Container
class Vector
Container <|-- Vector
class Map
Container <|-- Map
class Stack
Container <|-- Stack
class Queue
Container <|-- Queue

class Active
Object <|-- Active
class VM
Active <|-- VM
class Cmd
Active <|-- Cmd
class Seq
Active <|-- Seq
```

- [[metaL/Object]]
	- [[metaL/Primitive]]
		- [[metaL/String]]
	- [[metaL/Container]]
		- [[metaL/Vector]]
		- [[metaL/Map]]
		- [[metaL/Stack]]
	- [[metaL/Active]]
	- [[metaL/VM]]
	- [[metaL/Cmd]]
	- [[metaL/Seq]]
	- [[metaL/GUI]]
	
