CC=g++
FLAG=-Wall -std=c++14
TARGET=multikeyHash
SRC=main.cpp multikeyHash.hpp toBytes.cpp
OBJS=main.o

multikeyHash: $(OBJS)
	$(CC) $(FLAG) -o $(TARGET) $(OBJS)

main.o: $(SRC)
	$(CC) $(FLAG) -c main.cpp

.PHONY:
	clean

clean:
	-rm *.o *.gch $(TARGET)