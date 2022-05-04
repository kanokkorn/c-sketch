CC = cc
CFLAGS = -std=c99 -Wall -Wextra -Wconversion -pedantic -O3

SRC = $(wildcard *.c)

PROG = $(patsubst %.c,%,$(SRC))

all: $(PROG)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<
clean:
	$(RM) -f $(PROG)
