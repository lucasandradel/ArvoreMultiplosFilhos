all: main.o ArvoreMF.o
	gcc main.o ArvoreMF.o -o prog
	./prog

main.o: main.c
	gcc -c main.c

ArvoreMF.o: ArvoreMF.c
	gcc -c ArvoreMF.c

clean:
	rm -f *.o prog
