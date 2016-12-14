.PHONY: all clean

CC = g++
CPPFLAGS = --std=c++11 -I src

SOURCES := $(shell find src -type f -name *.cpp)
OBJECTS := $(patsubst src/%,build/%, $(subst .cpp,.o, $(SOURCES))) build/parser.o build/lexer.o

TARGET = bin/telegraph

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p bin
	$(CC) $(OBJECTS) -o bin/telegraph

build/lexer.o: build/parser.o

build/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) -c $< -o $@


src/%.cpp: src/%.l
	flex -o $@ $<

src/%.cpp: src/%.y
	bison --debug -o $@ -d $<

clean:
	rm -rf bin
	rm -rf build
