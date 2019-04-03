CC = clang

hello: hello.c 
	 hello.c -o hello.o

2d-array: 2d-array.c
	 2d-array.c -o 2d-array.o

clean:
	rm *.o

.PHONY = all clean