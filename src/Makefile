CC = gcc
CCFL = -Wall -Werror -Wextra -std=c11

all:

tests: list_tests parser_tests

list_tests: tests/lexunit-list-tests.c .bin/lexunit-list.o prepare
	$(CC) $(CCFL) -g -c $< -o .bin/lexunit-list-tests.o
	$(CC) $(CCFL) -g .bin/lexunit-list-tests.o .bin/lexunit-list.o -o ../build/$@

parser_tests: tests/lexunit-parser-tests.c .bin/lexunit-parser.o .bin/lexunit-list.o prepare
	$(CC) $(CCFL) -g -c $< -o .bin/lexunit-parser-tests.o
	$(CC) $(CCFL) -g .bin/lexunit-list.o .bin/lexunit-parser.o .bin/lexunit-parser-tests.o -o ../build/$@

.bin/lexunit-list.o: lexunit-list.c prepare
	$(CC) $(CCFL) -g -c $< -o $@

.bin/lexunit-parser.o: lexunit-parser.c prepare
	$(CC) $(CCFL) -g -c $< -o $@

prepare:
	mkdir -p .bin
	mkdir -p ../build

clean:
	rm -rf .bin
	rm -rf ../build/*

rebuild: clean all
