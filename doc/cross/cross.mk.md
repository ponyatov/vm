# mk/cross.mk

```Makefile
HW   ?= pc
include hw/$(HW)/$(HW).mk
include cpu/$(CPU)/$(CPU).mk
include arch/$(ARCH)/$(ARCH).mk

TCC   = $(TARGET)-gcc
TXX   = $(TARGET)-g++
TLD   = $(TARGET)-ld
TOD   = $(TARGET)-objdump
TSIZE = $(TARGET)-size

include os/$(OS)/$(OS).mk
```

## [[cross/hw]]
## [[cross/cpu]]
## [[cross/arch]]
## [[cross/os]]
