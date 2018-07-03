# I need to fix this eventualy. Still a bit new to makefiles, havent had to make
# many myself. If i'm honest this is one i found somewhere that i've been 
# dragging with me.
TARGET = nameGen convertFromCp utilities itoa shopGen settlementGen test regionGen
LIBS = -lm
CC = gcc
CFLAGS = -g -Wall

.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)
