CC = g++

all: graphEditor clean

graphEditor: main.o graph.o userInterface.o
	$(CC) main.o graph.o userInterface.o -o graphEditor

main.o: main.cpp
	$(CC) -c main.cpp -Wall

graph.o: Graph.cpp Graph.h
	$(CC) -c Graph.cpp -Wall

userInterface.o: userInterface.cpp userInterface.h
	$(CC) -c userInterface.cpp -Wall

clean:
	rm -f *.o
