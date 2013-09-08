all: lex.yy.c
	g++ -o cpsllexer lex.yy.c -lfl -ll -ly

lex.yy.c: cpsl.l
	flex cpsl.l

tar: clean
	tar -cvzf cpsl_bowen_masco.tgz cpsl.l makefile

clean:
	rm -f lex.yy.c
	rm -f cpsllexer
	rm -f cpsl.tab.c
	rm -f cpsl.tab.h
