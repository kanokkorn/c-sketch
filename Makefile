CC = cc
CFLAGS = -std=c99 -Wall -Wextra -Wconversion -pedantic -O3

SRCS = $(wildcard *.c)

PROGS = $(patsubst %.c,%,$(SRCS))

all: $(PROGS)

%: %.c
			$(CC) $(CFLAGS)  -o $@ $<
clean:
			rm -rf *.o $(PROGS)
