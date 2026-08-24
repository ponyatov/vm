# gcc0

minimal [[cpp/gcc|gcc]] build required only for [[cross/linux]] and [[cross/uclibc]]

```Makefile
.PHONY: gcc0

GCC0_CFG  = $(BINUTILS_CFG) $(CCLIBS_WITH) --enable-languages="c"
GCC0_CFG += --disable-threads --without-headers --with-newlib

gcc0: $(CROSS)/bin/$(TCC)
$(CROSS)/bin/$(TCC): $(CROSS)/bin/$(TLD) $(CCLIBS) $(REF)/$(GCC)/README.md
	mkdir -p $(TMP)/$(GCC) ; cd $(TMP)/$(GCC) ;\
	$(TPATH) $(REF)/$(GCC)/configure $(GCC0_CFG)
	cd $(TMP)/$(GCC) ; $(MAKE) all-gcc
	cd $(TMP)/$(GCC) ; $(MAKE) install-gcc
```

- only C language supported
- no libc or threads enabled

## init

[[gcc0]] also can be used for init stub compiling: static ELF executable without libc or any other dependencies

```Makefile
.PHONY: init
init: $(ROOT)/bin/init
$(ROOT)/bin/init: src/init.c os/linux/linux.mk
	$(TPATH) $(TCC) \
		-static -nostdlib -ffreestanding -fno-stack-protector -fno-builtin \
		-o $@ $< && file $@ && $(TSIZE) $@
```
