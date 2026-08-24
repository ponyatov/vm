```Makefile
gmp: $(CROSS)/lib/libgmp.a
GMP_CFG     = $(CCLIBS_CFG)
$(CROSS)/lib/libgmp.a:
	$(MAKE) $(REF)/$(GMP)/README.md
	mkdir -p $(TMP)/$(GMP) ; cd $(TMP)/$(GMP) ;\
	$(TPATH) $(REF)/$(GMP)/configure $(GMP_CFG) &&\
	$(MAKE) && $(MAKE) install-strip &&\
	touch $@ ; rm -rf $(REF)/$(GMP) $(TMP)/$(GMP)
```
