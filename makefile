src = $(wildcard RPGutilities/*.c) \
		$(wildcard Utilities/*.c) \
		$(wildcard WorldGen/*.c) \
		$(wildcard *.c)

obj = $(src:.c=.o)

CC = gcc
FLAGS = -Wall

all: $(obj)
	$(CC) -o $@ $^ $(FLAGS)

.PHONY: clean
clean:
	rm -f $(obj) all