CC = gcc
TETETETET = -fsanitize=leak -fsanitize=address -fsanitize=undefined -fsanitize=unreachable -fno-sanitize-recover -fstack-protector
CCFL = -Wall -Werror -Wextra -std=c11

all:

tests: list_tests parser_tests stack_tests translate-tests

list_tests: tests/lexunit-list-tests.c .bin/lexunit-list.o .bin/lexunit.o prepare
	$(CC) $(CCFL) -g -c $< -o .bin/lexunit-list-tests.o
	$(CC) $(CCFL) -g .bin/lexunit-list-tests.o .bin/lexunit-list.o .bin/lexunit.o -o ../build/$@

parser_tests: tests/lexunit-parser-tests.c .bin/lexunit-parser.o .bin/lexunit-list.o .bin/lexunit.o prepare
	$(CC) $(CCFL) -g -c $< -o .bin/lexunit-parser-tests.o
	$(CC) $(CCFL) -g .bin/lexunit-list.o .bin/lexunit-parser.o .bin/lexunit-parser-tests.o .bin/lexunit.o -o ../build/$@

stack_tests: tests/lexunit-stack-tests.c .bin/lexunit-stack.o .bin/lexunit.o prepare
	$(CC) $(CCFL) -g -c $< -o .bin/lexunit-stack-tests.o
	$(CC) $(CCFL) -g .bin/lexunit-stack.o .bin/lexunit-stack-tests.o .bin/lexunit.o -o ../build/stack_tests

translate-tests: tests/rpn-translate-tests.c .bin/lexunit-stack.o .bin/lexunit-parser.o .bin/lexunit-list.o .bin/lexunit.o .bin/rpn-translate.o prepare
	$(CC) $(CCFL) -g -c $< -o .bin/translate-tests.o
	$(CC) $(CCFL) -g .bin/lexunit-parser.o .bin/lexunit-list.o .bin/lexunit.o .bin/rpn-translate.o .bin/lexunit-stack.o .bin/translate-tests.o -o ../build/translate-tests

.bin/lexunit.o: lexunit.c prepare
	$(CC) $(CCFL) -g -c $< -o $@

.bin/lexunit-stack.o: lexunit-stack.c prepare
	$(CC) $(CCFL) -g -c $< -o $@

.bin/lexunit-list.o: lexunit-list.c prepare
	$(CC) $(CCFL) -g -c $< -o $@

.bin/lexunit-parser.o: lexunit-parser.c prepare
	$(CC) $(CCFL) -g -c $< -o $@

.bin/rpn-translate.o: rpn-translate.c prepare
	$(CC) $(CCFL) -g -c $< -o $@

prepare:
	mkdir -p .bin
	mkdir -p ../build

clean:
	rm -rf .bin
	rm -rf ../build/*

rebuild: clean all
