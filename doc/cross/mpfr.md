```Makefile
mpfr: $(CROSS)/lib/libmpfr.a
MPFR_CFG    = $(CCLIBS_CFG)
$(CROSS)/lib/libmpfr.a:
	$(MAKE) $(REF)/$(MPFR)/README.md
	mkdir -p $(TMP)/$(MPFR) ; cd $(TMP)/$(MPFR) ;\
	$(TPATH) $(REF)/$(MPFR)/configure $(MPFR_CFG) &&\
	$(MAKE) && $(MAKE) install-strip &&\
	touch $@ ; rm -rf $(REF)/$(MPFR) $(TMP)/$(MPFR)
```
