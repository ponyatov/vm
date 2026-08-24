# metaL

- meta Layer
- meta Language

- [[lang/metaprogramming]]
- [[metacircular]]

## [[object graph]] core

- [[vm/Object]] base object (hyper)graph node
	- [[Primitive]]
		- [[S]] nested string = source code
		- [[Sym]] symbol
		- [[Num]] number
			- [[vm/Int]] integer
				- [[Hex]]
				- [[Bin]]
	- [[VM/Container]]
		- [[Map]]
		- [[vm/Vector]]
		- [[Stack]]
		- [[Queue]]
	- [[Active]]
		- [[Cmd]]
		- [[metaL/VM]]
		- [[Fn]]
		- [[D/op]]
	- [[Meta]]
		- [[Module]]
		- [[D/class]]
	- [[IO]]
		- [[cmake/dirs]]
		- [[D/file]]
		- [[Net]]
			- [[IP]]
			- [[Port]]
			- [[TCP]]
			- [[UDP]]
			- [[Socket]]
	- [[D/GUI]]
		- [[GUI/Frame]]
		- [[Text]]
		- [[Button]]


