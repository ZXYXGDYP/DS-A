all: list
list: removal main.o
	g++ -o list main.o
main.o: main.cpp
	g++ -c -g main.cpp
removal:
	rm -f *.o
