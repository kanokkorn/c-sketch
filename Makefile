cc = cc
cflags = -std=c11 -Wall -Wextra -Wconversion -pedantic -O3

src = $(wildcard *.c)

prog = $(patsubst %.c,%,$(src))

all: $(prog)

%: %.c
	$(cc) $(cflags) -o $@ $<
clean:
	rm -f $(prog)
