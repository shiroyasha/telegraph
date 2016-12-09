.PHONY: all test

CC = g++
CFLAGS = --std=c++11 -I src -c
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
	$(CC) $(CFLAGS) src/lexer.yy.c -o bin/lexer.o

bin/parser.o: bin src/parser.y
	yacc --debug -o src/parser.tab.c -d src/parser.y
	$(CC) $(CFLAGS) src/parser.tab.c -o bin/parser.o

bin/telegraph.o: bin src/telegraph.cpp
	$(CC) $(CFLAGS) src/telegraph.cpp -o bin/telegraph.o

bin/tests/lexer_test.o: bin/tests test/lexer_test.cpp
	$(CC) $(CFLAGS) test/lexer_test.cpp -o bin/tests/lexer_test.o


# binaries

bin/telegraph: bin/lexer.o bin/parser.o bin/telegraph.o
	$(CC) bin/lexer.o bin/parser.o bin/telegraph.o -o bin/telegraph

bin/tests/lexer_test: bin/tests bin/lexer.o bin/tests/lexer_test.o
	$(CC) bin/lexer.o bin/parser.o bin/tests/lexer_test.o $(TEST_LIBS) -o bin/tests/lexer_test
