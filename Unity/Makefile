CC = g++
FLAG = -Wall -std=c++11
TARGET = bin/strt
OBJS = Dictionary.o strt.o
INCLUDE = include
SRC = src

all: $(OBJS)
	$(CC) $(FLAG) -o $(TARGET) $(OBJS)
strt.o: $(SRC)/strt.cpp
	$(CC) $(FLAG) -c $(SRC)/strt.cpp
Dictionary.o: $(INCLUDE)/Dictionary.h $(SRC)/Dictionary.cpp
	$(CC) $(FLAG) -c $(SRC)/Dictionary.cpp $(INCLUDE)/Dictionary.h

clean:
	rm *.o $(TARGET) $(INCLUDE)/*.gch