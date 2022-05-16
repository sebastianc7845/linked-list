CFLAGS = -g -ansi -Wall -Werror -pedantic-errors -fstack-protector
CC = gcc

all: test1.x test2.x test3.x test4.x test5.x test6.x

test1.x: test1.o linked-list.o
	$(CC) test1.o linked-list.o -o test1.x

test2.x: test2.o linked-list.o
	$(CC) test2.o linked-list.o -o test2.x

test3.x: test3.o linked-list.o
	$(CC) test3.o linked-list.o -o test3.x

test4.x: test4.o linked-list.o
	$(CC) test4.o linked-list.o -o test4.x

test5.x: test5.o linked-list.o
	$(CC) test5.o linked-list.o -o test5.x

test6.x: test6.o linked-list.o
	$(CC) test6.o linked-list.o -o test6.x

linked-list.o: linked-list.h linked-list.c
	$(CC) $(CFLAGS) -c linked-list.c

test1.o: linked-list.h test1.c
	$(CC) $(CFLAGS) -c test1.c

test2.o: linked-list.h test2.c
	$(CC) $(CFLAGS) -c test2.c

test3.o: linked-list.h test3.c
	$(CC) $(CFLAGS) -c test3.c

test4.o: linked-list.h test4.c
	$(CC) $(CFLAGS) -c test4.c

test5.o: linked-list.h test5.c
	$(CC) $(CFLAGS) -c test5.c

test6.o: linked-list.h test6.c
	$(CC) $(CFLAGS) -c test6.c
