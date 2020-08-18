stack: main.o Stack.o Node.o
	g++ main.o Stack.o Node.o -o stack
Node.o: Node.h Node.cpp
	g++ -c Node.cpp 
main.o: Stack.h utility.h main.cpp
	g++ -c main.cpp 
Stack.o: Node.h Stack.h utility.h Stack.cpp
	g++ -c Stack.cpp
clean:
	rm -f *.o stack
