CC = g++
CFLAGS = --std=c++11 -Wall -c
LFLAGS = --std=c++11
SRC = src
OBJ = obj
DOC = doc
TEST = test

all: roman

roman: $(OBJ)/main.o $(OBJ)/roman.o
	$(CC) $(LFLAGS) $(OBJ)/main.o $(OBJ)/roman.o -o roman

$(OBJ)/main.o: $(SRC)/main.cpp $(SRC)/roman.hpp
	$(CC) $(CFLAGS) $(SRC)/main.cpp -o $(OBJ)/main.o

$(OBJ)/roman.o: $(SRC)/roman.cpp $(SRC)/roman.hpp
	$(CC) $(CFLAGS) $(SRC)/roman.cpp -o $(OBJ)/roman.o

.PHONY: clean doc test

doc:
	doxygen doxyfile

test:
	./test.sh

clean:
	rm -rf $(OBJ)/* roman
