hello: hello.o 
	clang hello.o -o hello.o

2d-array: 2d-array.o
	clang 2d-array.o -o 2d-array.o

clean:
	rm *.o