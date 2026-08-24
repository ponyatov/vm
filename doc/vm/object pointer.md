# object pointer
#ST
## [[oops]]

> The [[object memory]] and [[vm/interpreter|interpreter]] communicate about [[vm/Object|Object]]s with [[object pointer]]s. 

The size of object pointers determines the [[SegmentSize|maximum number of objects]] a [[Smalltalk/80]] system can contain. This number is not fixed by anything about the language, but the implementation described in this book uses [[RealWordMemory|16-bit object pointers]], allowing $2^{16} = 65536$ objects to be referenced. [[Implementation]] of the [[Smalltalk/80]] system with larger object references will require changing certain parts of the virtual machine specification. It is not within the scope of this book to detail the relevant changes.
