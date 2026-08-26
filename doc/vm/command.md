# command

The [[vm/vm|vm]] uses a **[[FORTH/FORTH|FORTH]]-inspired stack-based command set** enhanced with embedded-specific and multitasking features.

## control flow

### nop
00 `( -- )` do nothing (empty command)

### halt
FF `( -- )` stop the whole [[vm/vm|vm]]

### call
01 `(R: -- addr)` nested call

### ref
02 `(R: addr -- )` return from [[#call]]

### jmp
03 `( -- )` unconditional jump

## [[vm/debug]]

### dump
DD `( -- )` dump [[vm/vm|vm]] state
