CC = g++
FLAG = -Wall -std=c++11
SRC = src
INCLUDE = include
OBJS = main.o PhoneKeypadAlias.o
TARGET = main

main: $(OBJS)
	$(CC) $(FLAG) -o $(TARGET) $(OBJS)
main.o: $(SRC)/main.cpp
	$(CC) $(FLAG) -c $(SRC)/main.cpp
PhoneKeypadAlias.o: $(SRC)/PhoneKeypadAlias.cpp $(INCLUDE)/PhoneKeypadAlias.h
	$(CC) $(FLAG) -c $(SRC)/PhoneKeypadAlias.cpp

clean:
	rm $(OBJS) $(TARGET)