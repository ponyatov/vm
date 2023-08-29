# var
PEPS    = E26,E302,E305,E401,E402,E701,E702

# tool
PEP     = autopep8

.PHONY: all install update
all: ../tmp/format_py
	python3 SOM.py SOM.ini

../tmp/format_py: SOM.py
	$(PEP) --ignore $(PEPS) -i $? && touch $@

install update:
	sudo apt update
	sudo apt install -uy `cat apt.txt`
