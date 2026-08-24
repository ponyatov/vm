# cclibs

set of libraries required for cross-gcc build:
- [[math/GMP|GMP]]
- [[math/MPFR|MPFR]]
- [[math/MPC|MPC]]


```Makefile
# version
GMP_VER      = 6.3.0
MPFR_VER     = 4.2.2
MPC_VER      = 1.4.1
```

```Makefile
# package
GMP      = gmp-$(GMP_VER)
MPFR     = mpfr-$(MPFR_VER)
MPC      = mpc-$(MPC_VER)
```

```Makefile
# source code
GMP_GZ      = $(GMP).tar.xz
MPFR_GZ     = $(MPFR).tar.xz
MPC_GZ      = $(MPC).tar.xz
```

```Makefile
# local mirror
GZ += $(HOME)/gz/$(GMP_GZ)
$(HOME)/gz/$(GMP_GZ):
	$(CURL) $@ $(YANDEX_GNU)/gmp/$(GMP_GZ)
GZ += $(HOME)/gz/$(MPFR_GZ)
$(HOME)/gz/$(MPFR_GZ):
	$(CURL) $@ $(YANDEX_GNU)/mpfr/$(MPFR_GZ)
GZ += $(HOME)/gz/$(MPC_GZ)
$(HOME)/gz/$(MPC_GZ):
	$(CURL) $@ $(YANDEX_GNU)/mpc/$(MPC_GZ)
```

```Makefile
# cclibs
.PHONY: cclibs gmp mpfr mpc
CCLIBS = $(CROSS)/lib/libgmp.a $(CROSS)/lib/libmpfr.a $(CROSS)/lib/libmpc.a
cclibs: $(CCLIBS)

CCLIBS_CFG  = --prefix=$(CROSS) --disable-shared
CCLIBS_WITH = --with-gmp=$(CROSS) --with-mpfr=$(CROSS) --with-mpc=$(CROSS)
```
![[cross/gmp]]
![[cross/mpfr]]
![[cross/mpc]]
