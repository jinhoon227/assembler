# Write this Makefile
myas: check.o trans.o main.o
	gcc -o myas trans.o check.o main.o
trans.o: trans.c
	gcc -c trans.c
check.o: check.c
	gcc -c check.c
main.o: main.c
	gcc -c main.c
clean:
	rm -rf check.o trans.o main.o 
