# var
MODULE = $(notdir $(CURDIR))

# tool
CURL = curl -L -o
CF   = clang-format

# src
C  += src/$(MODULE).cpp
H  += inc/$(MODULE).hpp
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
doc: doc/beam-book.pdf

doc/beam-book.pdf:
	$(CURL) $@ https://github.com/happi/theBeamBook/releases/download/latest/beam-book.pdf

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
