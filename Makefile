.PHONY: all test

CC = g++
FLAGS = --std=c++11 -I src
TEST_LIBS = -lpthread -lgtest

all: bin/telegraph

test: bin/tests/lexer_test
	./bin/tests/lexer_test

bin:
	mkdir -p bin

bin/tests: bin
	mkdir -p bin/tests


# objects

bin/lexer.o: bin bin/parser.o src/lexer.l
	flex -o src/lexer.yy.c src/lexer.l
	$(CC) $(FLAGS) -c src/lexer.yy.c -o bin/lexer.o

bin/parser.o: bin src/parser.y
	yacc --debug -o src/parser.tab.c -d src/parser.y
	$(CC) $(FLAGS) -c src/parser.tab.c -o bin/parser.o

bin/telegraph.o: bin src/telegraph.cpp
	$(CC) $(FLAGS) -c src/telegraph.cpp -o bin/telegraph.o

bin/tests/lexer_test.o: bin/tests test/lexer_test.cpp
	$(CC) $(FLAGS) -c test/lexer_test.cpp -o bin/tests/lexer_test.o


# binaries

bin/telegraph: bin/lexer.o bin/parser.o bin/telegraph.o
	$(CC) $(FLAGS) bin/lexer.o bin/parser.o bin/telegraph.o -o bin/telegraph

bin/tests/lexer_test: bin/tests bin/lexer.o bin/tests/lexer_test.o
	$(CC) $(FLAGS) bin/lexer.o bin/parser.o bin/tests/lexer_test.o $(TEST_LIBS) -o bin/tests/lexer_test
