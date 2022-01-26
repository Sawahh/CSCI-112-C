#include <stdio.h>
#include <string.h>
#include "grades.h"

int ReadGrades(Student_t* students) {

    FILE* infptr = fopen("/public/examples/pgm1/grades.txt", "r");

    char line[80];

    char *result;

    int i = 0;

    if (infptr == NULL) {
        printf("ERROR: could not open input file\n");
    }

    while (fgets(line, sizeof(line), infptr) != NULL) {
        result = strtok(line, ",");
        strcpy(students[i].last_name, result);
      
        result = strtok(NULL, ",");
        strcpy(students[i].first_name, result);        

        result = strtok(NULL, ",");
        sscanf(result, "%lf", &students[i].grade);
   
        ++i;
    }
    fclose(infptr);
    return i;
} 
