SRCS != ls *.c

# PROGS = $(patsubst %.c,%,$(SRCS))
PROGS = ${patsubst %.c,%,${SRCS}}

all: ${PROGS}

%: %.c
			${CC} ${CFLAGS}  -o $@ $<
clean:
			rm -rf *.o ${PROGS}
