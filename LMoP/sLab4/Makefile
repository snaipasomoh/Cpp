CC=g++
CFLAGS=-c -Wall -std=c++17

lab: main.o dataObj.o
	$(CC) main.o dataObj.o -o lab

main.o: main.cpp dataObj.h delist.h
	$(CC) $(CFLAGS) main.cpp

dataObj.o: dataObj.cpp dataObj.h
	$(CC) $(CFLAGS) dataObj.cpp

.PHONY: clear

clear:
	$(RM) -r *.o *.gch lab.*
