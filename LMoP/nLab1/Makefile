CC=g++
CFLAGS=-c -Wall -std=c++17

lab: main.o dataObj.o delist.o
	$(CC) main.o dataObj.o delist.o -o lab

main.o: main.cpp delist.h dataObj.h
	$(CC) $(CFLAGS) main.cpp

delist.o: delist.cpp delist.h dataObj.h
	$(CC) $(CFLAGS) delist.cpp

dataObj.o: dataObj.cpp dataObj.h
	$(CC) $(CFLAGS) dataObj.cpp
	
.PHONY: clear

clear:
	$(RM) -r *.o lab
