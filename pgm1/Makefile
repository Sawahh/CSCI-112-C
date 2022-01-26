
pgm1: print_grades.o read_grades.o calculate.o main.o
	gcc -o pgm1 -Wall print_grades.o read_grades.o calculate.o main.o

print_grades.o: print_grades.c student_arr.h
	gcc -c -Wall print_grades.c

calculate.o: calculate.c student_arr.h
	gcc -c -Wall calculate.c

read_grades.o: read_grades.c student_arr.h
	gcc -c -Wall read_grades.c

main.o: main.c student_arr.h
	gcc -c -Wall main.c
