#include <stdio.h>
#include "grades.h"

void PrintGrades(Student_t* students, int n) {
    
    FILE* outfptr = fopen("out.txt", "w");

    for (int i = 0; i < n; ++i) {
        fprintf(outfptr, "Name: %s %s\tGrade: %-4lf %-3s Curved? %c\n",
                          students[i].first_name, students[i].last_name,
                          students[i].grade, students[i].letter_grade,
                          students[i].curved);
    }
    fclose(outfptr);
    return;
}

