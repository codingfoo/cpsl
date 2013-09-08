all: lex.yy.c
	gcc -o cpsllexer lex.yy.c -lfl

lex.yy.c: cpsl.lex
	flex cpsl.lex


clean:
	rm -f lex.yy.c
	rm -f cpsllexer
	rm -f cpsl.tab.c
	rm -f cpsl.tab.h
