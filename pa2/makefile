

CC = gcc -std=c17

all: List.o Graph.o FindPath.o ListTest.o GraphTest.o
	$(CC) List.o ListTest.o Graph.o GraphTest.o FindPath.o -o out
	
FindPath: FindPath.c
	$(CC) -c FindPath.c -o FindPath.o

List: List.c
	$(CC) -c List.c -o List.o
	
ListTest: ListTest.c
	$(CC) -c ListTest.c -o ListTest.o
	
Graph: Graph.c
	$(CC) -c Graph.c -o Graph.o

GraphTest: GraphTest.c
	$(CC) -c GraphTest.c -o GraphTest.o
	
clean:
	rm -rf *.o out
