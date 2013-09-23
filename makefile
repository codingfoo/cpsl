all: test

test: build
	./cpsl test/syntax.cpsl

build: cpsl.tab.c lex.yy.c
	clang++ -g -std=c++11 -stdlib=libc++ cpsl.tab.c lex.yy.c  -lfl -ll -ly -o cpsl

test_lex: build_lex
	./cpsl_lexer test/lex.cpsl

build_lex: lex.yy.c
	clang++ -std=c++11 -stdlib=libc++ lex.yy.c -o cpsl_lexer

lex.yy.c: cpsl.lex cpsl.tab.h
	flex cpsl.lex

cpsl.tab.c cpsl.tab.h: cpsl.y
	bison -d cpsl.y

tar: clean
	tar -cvzf cpsl_bowen_masco.tgz cpsl.lex makefile

clean:
	rm -f lex.yy.c
	rm -f cpsl_lexer
	rm -rf cpsl.dSYM
	rm -f cpsl.tab.c
	rm -f cpsl.tab.h
	rm -f cpsl
