#Bison Version 3.0
BISON=/usr/local/opt/bison/bin/bison
FLEX=flex
CC=/usr/local/bin/g++-4.8
SOURCES=$(wildcard **/*.cpp)
HEADERS=$(wildcard **/*.h)
CFLAGS=-Wall -g -std=c++11
LDFLAGS=-lfl -ll -ly
EXECUTABLE=cpsl

all: clean test

test: build
	./cpsl -v test/expression.cpsl

build: cpsl.tab.c lex.yy.c $(SOURCES)
	$(CC) $(CFLAGS) $(LDFLAGS) cpsl.tab.c lex.yy.c $(SOURCES) -o $(EXECUTABLE)

lex.yy.c: cpsl.lex cpsl.tab.c cpsl.tab.h
	$(FLEX) cpsl.lex

cpsl.tab.c cpsl.tab.h: cpsl.y
	$(BISON) -d cpsl.y

zip: clean
	zip cpsl_bowen_masco.zip cpsl.lex cpsl.y $(SOURCES) $(HEADERS) makefile

clean:
	rm -f lex.yy.c
	rm -f cpsl_lexer
	rm -rf cpsl.dSYM
	rm -f cpsl.tab.c
	rm -f cpsl.tab.h
	rm -f cpsl
	rm -f cpsl.output
