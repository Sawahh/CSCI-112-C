#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student_arr.h"

int read_grades(Student_t students[]){
	int length = sizeof(char)*128; // Allows for memory to change

	char *result;
	char first[20], last[20], grade[20]; // Temporary storage
	int i = 0; // Make counter

	result = (char*) malloc(length); 
	if(result == NULL){ // A nicer way to break if no memory
		printf("memory failed");
		return (-1);
	}

	FILE *fptr = fopen("grades.txt", "r"); // Open txt file
	if (fptr == NULL){ // Check if error opening file
		printf("Cannot open file");
		return (-1);
	}

	// While loop to set values in struct array from read file
	while (fgets(result, length, fptr) != NULL){
		strcpy(last, strtok(result, ","));
		strcpy(first, strtok(NULL, ","));
		strcpy(grade, strtok(NULL, ","));

		strcpy(students[i].name, first);
		strcat(students[i].name, " ");
		strcat(students[i].name, last);
		students[i].grade = strtod(grade, NULL);
		i++;
	}
	students[i].name[0] = '\0'; // Set the end
	fclose(fptr); // Close file
	return i; // Return how many students there are
}
