src = $(wildcard RPGutilities/*.c) \
		$(wildcard Utilities/*.c) \
		$(wildcard WorldGen/*.c) \
		$(wildcard *.c)

obj = $(src:.c=.o)

CC = gcc
FLAGS = -Wall

test: $(obj)
	$(CC) $(FLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f $(obj) all