CC=g++
CFLAGS=-c -Wall -std=c++17

vLab3: main.o state.o stack.o list.o
	$(CC) main.o state.o stack.o list.o -o vLab3

main.o: main.cpp list.hpp stack.hpp state.hpp
	$(CC) $(CFLAGS) main.cpp

state.o: state.cpp state.hpp
	$(CC) $(CFLAGS) state.cpp

list.o: list.cpp list.hpp state.hpp
	$(CC) $(CFLAGS) list.cpp

stack.o: stack.cpp stack.hpp state.hpp list.hpp
	$(CC) $(CFLAGS) stack.cpp

.PHONY: clear

clear:
	$(RM) -r *.o *.gch vLab3 *.txt
