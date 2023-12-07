



CC = clang++



all: source flower flowertree Sunflower TigerLily
	$(CC) source.o flower.o flowertree.o Sunflower.o TigerLily.o -o out
	
source: source.cpp
	$(CC) -c source.cpp -o source.o

flower: flower.cpp
	$(CC) -c flower.cpp -o flower.o

flowertree: flowertree.cpp
	$(CC) -c flowertree.cpp -o flowertree.o

Sunflower: Sunflower.cpp
	$(CC) -c Sunflower.cpp -o Sunflower.o

TigerLily: TigerLily.cpp
	$(CC) -c TigerLily.cpp -o TigerLily.o

clean:
	rm -rf *.o out
