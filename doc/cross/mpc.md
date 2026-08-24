```Makefile
mpc: $(CROSS)/lib/libmpc.a
MPC_CFG     = $(CCLIBS_CFG) --with-mpfr=$(CROSS)
$(CROSS)/lib/libmpc.a:
	$(MAKE) $(REF)/$(MPC)/README.md
	mkdir -p $(TMP)/$(MPC) ; cd $(TMP)/$(MPC) ;\
	$(TPATH) $(REF)/$(MPC)/configure $(MPC_CFG) &&\
	$(MAKE) && $(MAKE) install-strip &&\
	touch $@ ; rm -rf $(REF)/$(MPC) $(TMP)/$(MPC)
```
