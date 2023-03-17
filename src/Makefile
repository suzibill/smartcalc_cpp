CC= g++ 
CFLAGS= -Wall -Wextra -Werror
STANDART= -std=c++17
TESTFLAGS=-lgtest
TESTFILES= tests/test.cc
SRC = model/*.cc

all: test1

test: $(TESTFILES) 
	./test

test1: $(TESTFILES)
	$(CC) $(TESTFILES) -o test $(TESTFLAGS) $(SRC) $(STANDART) -g -DDEBUG
	./test

leak: 
	leaks -atExit -- ./test