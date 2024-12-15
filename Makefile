CC = gcc
TARGET = swarm

all: $(TARGET)

queen: ./src/queen/*.c
	$(CC) ./src/queen/*.c -o ./bin/queen

initiator: ./src/initiator/*.c 
	$(CC) ./src/initiator/*.c ./src/common/*.c -o ./bin/initiator

$(TARGET): initiator queen

clean:
	rm -f ./bin/*