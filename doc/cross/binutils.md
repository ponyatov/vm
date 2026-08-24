# binutils

`binutils` is the standard GNU toolchain package containing assembler, linker, and other binary utilities.

|Tool|Purpose|
|---|---|
|**as**|GNU Assembler - converts assembly to object code|
|**ld**|GNU Linker - combines object files into executables|
|**ar**|Archive creator - builds static libraries (.a files)|
|**objcopy**|Object file manipulation|
|**objdump**|Display object file information|
|**size**|Show section sizes|
|**strip**|Remove debug symbols|
|**nm**|List symbols from object files|
|**readelf**|Display ELF file information|

```Makefile
.PHONY: binutils

BINUTILS_CFG  = --prefix=$(CROSS) --target=$(TARGET) --disable-nls
BINUTILS_CFG += --with-sysroot=$(ROOT) --with-native-system-header-dir=/usr/include
BINUTILS_CFG += --enable-lto --disable-multilib

binutils: $(CROSS)/bin/$(TLD)
$(CROSS)/bin/$(TLD):
	$(MAKE) $(REF)/$(BINUTILS)/README.md
	mkdir -p $(TMP)/$(BINUTILS) ; cd $(TMP)/$(BINUTILS) ;\
	$(TPATH) $(REF)/$(BINUTILS)/configure $(BINUTILS_CFG) &&\
	$(MAKE) && $(MAKE) install-strip &&\
	touch $@ ; rm -rf $(REF)/$(BINUTILS) $(TMP)/$(BINUTILS)
```

## target selection

|Flag|Meaning|Example Value|
|---|---|---|
|`--prefix=$(CROSS)`|Installation directory|project-local `~/project/cross`|
|`--target=$(TARGET)`|Target architecture|`i386-linux-uclibc`|
|`--disable-nls`|Disable Native Language Support|Reduces size (only english messages in compilers)|

## [[cross/sysroot|sysroot]]

|Flag|Purpose|
|---|---|
|`--with-sysroot=$(ROOT)`|Set system root directory|
|`--with-native-system-header-dir=/usr/include`|Where to find headers|
