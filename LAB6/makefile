compile: main.o file_related.o array_related.o
	gcc -o compile main.o file_related.o array_related.o
main.o: main.c
	gcc -c main.c
file_related.o: file_related.c
	gcc -c file_related.c
array_related.o: array_related.c
	gcc -c array_related.c
clean: 
	rm -f *.o compile