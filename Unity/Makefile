CC = g++
FLAG = -Wall -std=c++11
TARGET = strt
OBJS = Dictionary.o strt.o

all: $(OBJS)
	$(CC) $(FLAG) -o $(TARGET) $(OBJS)
strt.o: strt.cpp
	$(CC) $(FLAG) -c strt.cpp
Dictionary.o: Dictionary.h Dictionary.cpp
	$(CC) $(FLAG) -c Dictionary.cpp

clean:
	rm *.o $(TARGET)