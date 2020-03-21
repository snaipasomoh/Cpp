CC=g++
CFLAGS=-c -Wall -std=c++17

vLab2: main.o state.o stack.o
	$(CC) main.o state.o stack.o -o vLab2

main.o: main.cpp stack.hpp state.hpp
	$(CC) $(CFLAGS) main.cpp

state.o: state.cpp state.hpp
	$(CC) $(CFLAGS) state.cpp

stack.o: stack.cpp stack.hpp state.hpp
	$(CC) $(CFLAGS) stack.cpp

.PHONY: clear

clear:
	$(RM) -r *.o *.gch vLab2 *.txt
