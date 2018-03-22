foo: foo.o
	gcc foo.o -o foo
foo.o: foo.c
	gcc -c foo.c
clean:
	rm -rf *.out *.o
