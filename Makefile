.PHONY: all test

CC = g++
CFLAGS = --std=c++11 -I src -I src/ast -c
TEST_LIBS = -lpthread -lgtest

all: bin/telegraph

test: bin/lexer_test bin/parser_test
	./bin/lexer_test
	./bin/parser_test

bin:
	mkdir -p bin

bin/tests: bin
	mkdir -p bin/tests


# objects

bin/ast.o: bin $(wildcard src/ast/*)
	$(CC) $(CFLAGS) src/ast/ast.cpp -o bin/ast.o

bin/lexer.o: bin bin/parser.o src/lexer.l
	flex -o src/lexer.yy.c src/lexer.l
	$(CC) $(CFLAGS) src/lexer.yy.c -o bin/lexer.o

bin/parser.o: bin src/parser.y
	yacc --debug -o src/parser.tab.c -d src/parser.y
	$(CC) $(CFLAGS) src/parser.tab.c -o bin/parser.o

bin/telegraph.o: bin src/telegraph.cpp
	$(CC) $(CFLAGS) src/telegraph.cpp -o bin/telegraph.o


# test objects

bin/lexer_test.o: bin/tests test/lexer_test.cpp
	$(CC) $(CFLAGS) test/lexer_test.cpp -o bin/lexer_test.o

bin/parser_test.o: bin/tests test/parser_test.cpp
	$(CC) $(CFLAGS) test/parser_test.cpp -o bin/parser_test.o


# binaries

bin/telegraph: bin/ast.o bin/lexer.o bin/parser.o bin/telegraph.o
	$(CC) bin/ast.o bin/lexer.o bin/parser.o bin/telegraph.o -o bin/telegraph


# test

bin/lexer_test: bin/tests bin/ast.o bin/lexer.o bin/parser.o bin/lexer_test.o
	$(CC) bin/ast.o bin/lexer.o bin/parser.o bin/lexer_test.o $(TEST_LIBS) -o bin/lexer_test

bin/parser_test: bin/tests bin/ast.o bin/lexer.o bin/parser.o bin/parser_test.o
	$(CC) bin/ast.o bin/lexer.o bin/parser.o bin/parser_test.o $(TEST_LIBS) -o bin/parser_test
