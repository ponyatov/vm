# var
MODULE = $(notdir $(CURDIR))
module = $(shell echo $(MODULE) | tr A-Z a-z)
OS     = $(shell uname -o|tr / _)
NOW    = $(shell date +%d%m%y)
REL    = $(shell git rev-parse --short=4 HEAD)
BRANCH = $(shell git rev-parse --abbrev-ref HEAD)

# tool
CURL = curl -L -o
CF   = clang-format

# src
C  += src/$(MODULE).cpp
H  += inc/$(MODULE).hpp
S  += $(C) $(H)
CP += tmp/$(MODULE).parser.cpp tmp/$(MODULE).lexer.cpp
HP += tmp/$(MODULE).parser.hpp

# cfg
CFLAGS += -pipe -O0 -g2 -Iinc -Itmp

# all
all: bin/$(MODULE) lib/$(MODULE).ini
	$^

# format
format: tmp/fortmat_cpp doxy

tmp/fortmat_cpp: $(C) $(H)
	$(CF) -style=google -i $? && touch $@

# rule
bin/$(MODULE): $(C) $(H) $(CP) $(HP)
	$(CXX) $(CFLAGS) -o $@ $(C) $(CP)

tmp/$(MODULE).parser.cpp: src/$(MODULE).yacc
	bison -o $@ $<
tmp/$(MODULE).lexer.cpp: src/$(MODULE).lex
	flex -o $@ $<

# doc
doc: doc/beam-book.pdf doc/Starting-FORTH.pdf

doc/beam-book.pdf:
	$(CURL) $@ https://github.com/happi/theBeamBook/releases/download/latest/beam-book.pdf
doc/Starting-FORTH.pdf:
	$(CURL) $@ https://www.forth.com/wp-content/uploads/2018/01/Starting-FORTH.pdf
doxy: doxy.gen
	rm -rf docs ; doxygen $< 1>/dev/null

# install
install: doc gz
	$(MAKE) update
update: src
	sudo apt update
	sudo apt install -yu `cat apt.txt`

gz:

src: src/AtomVM/README.Md

src/AtomVM/README.Md:
	git clone https://github.com/atomvm/AtomVM.git src/AtomVM

# merge
MERGE  = Makefile README.md .clang-format doxy.gen $(S)
MERGE += apt.txt
MERGE += .vscode bin doc lib inc src tmp

dev:
	git push -v
	git checkout $@
	git pull -v
	git checkout shadow -- $(MERGE)
	$(MAKE) doxy ; git add -f docs

shadow:
	git push -v
	git checkout $@
	git pull -v

release:
	git tag $(NOW)-$(REL)
	git push -v --tags
	$(MAKE) shadow

ZIP = tmp/$(MODULE)_$(NOW)_$(REL)_$(BRANCH).zip
zip:
	git archive --format zip --output $(ZIP) HEAD
