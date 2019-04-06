CC = gcc

hello.o: hello.c 
	@echo "Crete Object file"
	CC hello.c -c hello.o

hello: hello.o
	@echo "Compile to binary file"
	CC hello.o -o hello

2d-array.o: 2d-array.c
	@echo "Crete Object file"
	CC 2d-array.c -c 2d-array.o

ad-array.o:
	@echo "Compile to binary file"
	CC 2d-array.o -o 2d-array

clean:
	rm *.o

.PHONY = all clean