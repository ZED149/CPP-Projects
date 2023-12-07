




all: Lex.o List.o ListTest.o main.o Queue.o QueueTest.o
	gcc Lex.o List.o ListTest.o main.o Queue.o QueueTest.o -o out
	

Lex.o: Lex.c
	gcc -c Lex.c -o Lex.o

List.o: List.c
	gcc -c List.c -o List.o

ListTest.o: ListTest.c
	gcc -c ListTest.c -o ListTest.o

main.o: main.c
	gcc -c main.c -o main.o

Queue.o: Queue.c
	gcc -c Queue.c -o Queue.o

QueueTest.o: QueueTest.c
	gcc -c QueueTest.c -o QueueTest.o




clean:
	rm -rf *.o out
