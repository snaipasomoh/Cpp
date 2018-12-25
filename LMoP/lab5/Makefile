CC=g++
CFLAGS=-c -Wall -std=c++17

lab1: main.o buyer.o
	$(CC) main.o buyer.o -o lab5

main.o: main.cpp buyer.h destack.h
	$(CC) $(CFLAGS) main.cpp

buyer.o: buyer.cpp buyer.h
	$(CC) $(CFLAGS) buyer.cpp

.PHONY: clear

clear:
	$(RM) -r *.o *.gch lab5
