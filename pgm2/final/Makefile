pgm2: main.o sortg.o calcg.o printg.o readg.o
	gcc -o pgm2 main.o sortg.o calcg.o printg.o readg.o

main.o: grades.h main.c
	gcc -c -Wall main.c

sortg.o: grades.h sortg.c
	gcc -c -Wall sortg.c

calcg.o: grades.h calcg.c
	gcc -c -Wall calcg.c

printg.o: grades.h printg.c
	gcc -c -Wall printg.c

readg.o: grades.h readg.c
	gcc -c -Wall readg.c
