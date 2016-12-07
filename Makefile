CC = g++
FLAGS = --std=c++11

bin/telegraph: bin src/lexer.yy.c
	$(CC) $(FLAGS) src/lexer.yy.c -I src -lfl -o bin/telegraph

bin:
	mkdir -p bin

src/lexer.yy.c: src/lexer.l
	flex -o src/lexer.yy.c src/lexer.l
