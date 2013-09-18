all: build

test: build
	./cpsl_lexer test.cpsl

build: lex.yy.c
	clang++ -std=c++11 -stdlib=libc++ lex.yy.c -o cpsl_lexer

lex.yy.c: cpsl.lex
	flex cpsl.lex

tar: clean
	tar -cvzf cpsl_bowen_masco.tgz cpsl.lex makefile

clean:
	rm -f lex.yy.c
	rm -f cpsl_lexer
	rm -f cpsl.tab.c
	rm -f cpsl.tab.h
