CC=g++
CFLAGS=-c -Wall -std=c++17

lab1: main.o dataObj.o
	$(CC) main.o dataObj.o -o lab5

main.o: main.cpp dataObj.h destack.h
	$(CC) $(CFLAGS) main.cpp

dataObj.o: dataObj.cpp dataObj.h
	$(CC) $(CFLAGS) dataObj.cpp

.PHONY: clear

clear:
	$(RM) -r *.o *.gch lab5
