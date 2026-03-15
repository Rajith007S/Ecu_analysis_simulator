CC = gcc

CFLAGS = -Wall -pthread -Iinclude
LDFLAGS = -lrt

SRC = src/main.c \
      src/sensor_proc.c \
      src/stats_analyzer.c \
      src/ecu_log.c \
      src/ipc.c

OBJ = $(SRC:.c=.o)

TARGET = ecu_system


all: $(TARGET)


$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


run: $(TARGET)
	./$(TARGET)


clean:
	rm -f src/*.o $(TARGET)
