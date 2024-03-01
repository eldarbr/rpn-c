CC = gcc
CCFL = -Wall -Werror -Wextra -std=c11

all:

tests: list_tests

list_tests: tests/lexunit-list-tests.c .bin/lexunit-list.o prepare
	$(CC) $(CCFL) -g -c $< -o .bin/lexunit-list-tests.o
	$(CC) $(CCFL) -g .bin/lexunit-list-tests.o .bin/lexunit-list.o -o ../build/$@

.bin/lexunit-list.o: lexunit-list.c prepare
	$(CC) $(CCFL) -g -c $< -o $@

prepare:
	mkdir -p .bin
	mkdir -p ../build

clean:
	rm -rf .bin
	rm -rf ../build/*

rebuild: clean all
