CC=g++
FLAG=-Wall -std=c++14

multikeyHash: main.o
	$(CC) $(FLAG) -o multikeyHash main.o

main.o: main.cpp multikeyHash.hpp
	$(CC) $(FLAG) -c main.cpp

.PHONY:
	clean

clean:
	-rm *.o *.gch