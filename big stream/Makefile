CC=g++
FLAG=-Wall -std=c++14

multikeyHash: main.o multikeyHash.o
	$(CC) $(FLAG) -o multikeyHash multikeyHash.o main.o

multikeyHash.o: multikeyHash.hpp toBytes.hpp
	$(CC) $(FLAG) -c multikeyHash.hpp

main.o: main.cpp multikeyHash.o
	$(CC) $(FLAG) -c main.cpp

.PHONY:
	clean

clean:
	-rm *.o *.gch