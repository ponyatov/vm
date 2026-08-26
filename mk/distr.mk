.PHONY: distr
distr: doc doxy
	zip -r tmp/$(BINFILE) bin/$(APP)_* lib/*.ini lib/*.u doc vscode
