pgm1: main.o calcg.o printg.o readg.o
	gcc -o pgm1 main.o calcg.o printg.o readg.o

main.o: grades.h main.c
	gcc -c -Wall main.c

calcg.o: grades.h calcg.c
	gcc -c -Wall calcg.c

printg.o: grades.h printg.c
	gcc -c -Wall printg.c

readg.o: grades.h readg.c
	gcc -c -Wall readg.c
