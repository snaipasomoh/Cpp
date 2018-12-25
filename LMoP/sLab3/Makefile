CC=g++
CFLAGS=-c -Wall -std=c++17

lab: main.o dataObj.o delist.o ordelist.o
	$(CC) main.o dataObj.o delist.o ordelist.o -o lab

main.o: main.cpp dataObj.h delist.h ordelist.h mExceptions.h
	$(CC) $(CFLAGS) main.cpp

dataObj.o: dataObj.cpp dataObj.h delist.h ordelist.h mExceptions.h
	$(CC) $(CFLAGS) dataObj.cpp

delist.o: delist.cpp dataObj.h delist.h ordelist.h mExceptions.h
	$(CC) $(CFLAGS) delist.cpp

ordelist.o: ordelist.cpp dataObj.h delist.h ordelist.h mExceptions.h
	$(CC) $(CFLAGS) ordelist.cpp

.PHONY: clear

clear:
	$(RM) -r *.o *.gch lab.*
