CC=/usr/local/bin/g++-4.8

all: test

test: build
	./cpsl -v test/syntax.cpsl

build: cpsl.tab.c lex.yy.c symbol.cpp symbol_table.cpp
	$(CC) -g -std=c++11 cpsl.tab.c lex.yy.c symbol.cpp symbol_table.cpp -lfl -ll -ly -o cpsl

test_lex: build_lex
	./cpsl_lexer test/lex.cpsl

build_lex: lex.yy.c
	$(CC) -std=c++11 lex.yy.c -o cpsl_lexer

lex.yy.c: cpsl.lex cpsl.tab.c cpsl.tab.h
	flex cpsl.lex

cpsl.tab.c cpsl.tab.h: cpsl.y
	bison -d cpsl.y

zip: clean
	zip cpsl_bowen_masco.zip cpsl.lex cpsl.y symbol.h symbol.cpp symbol_table.h symbol_table.cpp makefile

clean:
	rm -f lex.yy.c
	rm -f cpsl_lexer
	rm -rf cpsl.dSYM
	rm -f cpsl.tab.c
	rm -f cpsl.tab.h
	rm -f cpsl
	rm -f cpsl.output
