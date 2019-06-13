CC := g++
SRCDIR := src
SRCDIR += src/pokemon_src
TSTDIR := testes
OBJDIR := build
BINDIR := bin

MAIN := program/main.cpp
TESTER := program/tester.cpp

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
TSTSOURCES := $(shell find $(TSTDIR) -type f -name *.$(SRCEXT))

CFLAGS := -g -Wall -O3 -std=c++11
INC := -I include/ -I third_party/ -I include/pokemon_include

$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

main: $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(INC) $(MAIN) $^ -o $(BINDIR)/main
	rm -rf src/*.o src/pokemon_src/*.o include/pokemon_include/*.o include/*.o

tests: $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(INC) $(TESTER) $(TSTSOURCES) $^ -o $(BINDIR)/tester
	$(BINDIR)/tester
	rm -rf src/*.o src/pokemon_src/*.o include/pokemon_include/*.o include/*.o

valgrind: main
	valgrind --leak-check=full --track-origins=yes $(BINDIR)/main

all: main

run: main
	$(BINDIR)/main

clean:
	$(RM) -r $(OBJDIR)/* $(BINDIR)/*

.PHONY: clean coverage
