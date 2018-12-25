CC=g++
CFLAGS=-c -Wall -std=c++17

lab1: main.o buyer.o
	$(CC) main.o buyer.o -o lab1

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

buyer.o: buyer.cpp
	$(CC) $(CFLAGS) buyer.cpp

.PHONY: clear

clear:
	$(RM) -r *.o lab1
