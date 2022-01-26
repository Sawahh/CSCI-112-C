#include <stdio.h>
#include "grades.h"

int main(void) {

    // allow plenty of memory for students
    Student_t students[100];

    // read in the file and put the data into an array of data structures
    int num_students = ReadGrades(students);

    // determine letter grade
    CalculateLetterGrade(students, num_students);

    // print out names, numerical grade and letter grade
    PrintGrades(students, num_students);

    return(0);
}

