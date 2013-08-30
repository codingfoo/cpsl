all: cpsl.lex
	flex cpsl.lex

clean:
	rm -rf lex.yy.c
