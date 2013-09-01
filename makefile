all: lex.yy.c
	g++ -o cpsllexer lex.yy.c -lfl

lex.yy.c: cpsl.lex
	flex cpsl.lex

clean:
	rm -rf lex.yy.c
