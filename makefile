CC=/usr/local/bin/g++-4.8

BASE_FLAGS =

# INCLUDE BASE DIRECTORY AND BOOST DIRECTORY FOR HEADERS
LDFLAGS = -I/usr/local/Cellar/boost/1.54.0/include -I/opt/local/include

# INCLUDE BASE DIRECTORY AND BOOST DIRECTORY FOR LIB FILES
LLIBFLAGS = -L/usr/local/Cellar/boost/1.54.0/

# SPECIFIY LINK OPTIONS
LINKFLAGS = -l boost_thread-mt

# FINAL FLAGS -- TO BE USED THROUGHOUT
FLAGS = $(BASE_FLAGS) $(LLIBFLAGS) $(LDFLAGS) $(LINKFLAGS)


all: test

test: build
	./cpsl test/syntax.cpsl

build: cpsl.tab.c lex.yy.c symbol.cpp symbol_table.cpp
	$(CC) $(FLAGS) -g -std=c++11 cpsl.tab.c lex.yy.c symbol.cpp symbol_table.cpp -lfl -ll -ly -o cpsl

test_lex: build_lex
	./cpsl_lexer test/lex.cpsl

build_lex: lex.yy.c
	$(CC) -std=c++11 lex.yy.c -o cpsl_lexer

lex.yy.c: cpsl.lex cpsl.tab.h
	flex cpsl.lex

cpsl.tab.c cpsl.tab.h: cpsl.y
	bison -d cpsl.y

zip: clean
	zip cpsl_bowen_masco.zip cpsl.lex cpsl.y makefile

clean:
	rm -f lex.yy.c
	rm -f cpsl_lexer
	rm -rf cpsl.dSYM
	rm -f cpsl.tab.c
	rm -f cpsl.tab.h
	rm -f cpsl
	rm -f cpsl.output
