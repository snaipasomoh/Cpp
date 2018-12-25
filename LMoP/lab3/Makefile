CC=g++
CFLAGS=-c -Wall -std=c++11

lab3: main.o buyer.o
	$(CC) main.o buyer.o -o lab3

main.o: main.cpp dStack.h dLinkedList.h buyer.h exceptions.h
	$(CC) $(CFLAGS) main.cpp

buyer.o: buyer.cpp buyer.h
	$(CC) $(CFLAGS) buyer.cpp

.PHONY: clear
clear:
	$(RM) -r *.o *.gch lab3.exe
