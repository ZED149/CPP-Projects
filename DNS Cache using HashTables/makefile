

CC = g++
CFLAGS = -std=c++11
all: main
	@echo "Build complete."
main: main.o HashTable.o DNSRecord.o Node.o
	$(CC) $(CFLAGS) main.o HashTable.o DNSRecord.o Node.o -o main
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
HashTable.o: HashTable.cpp HashTable.h Node.h DNSRecord.h
	$(CC) $(CFLAGS) -c HashTable.cpp
DNSRecord.o: DNSRecord.cpp DNSRecord.h
	$(CC) $(CFLAGS) -c DNSRecord.cpp
Node.o: Node.cpp Node.h DNSRecord.h
	$(CC) $(CFLAGS) -c Node.cpp
clean:
	rm -f *.o main
