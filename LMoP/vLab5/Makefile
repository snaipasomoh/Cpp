CC=g++
CFLAGS=-c -Wall -std=c++17

vLab5: main.o state.o
	$(CC) main.o state.o -o vLab5

main.o: main.cpp stack.hpp state.hpp
	$(CC) $(CFLAGS) main.cpp

state.o: state.cpp state.hpp
	$(CC) $(CFLAGS) state.cpp

.PHONY: clear

clear:
	$(RM) -r *.o *.gch vLab5 *.txt
