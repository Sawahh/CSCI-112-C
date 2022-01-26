#include <stdio.h>
#include "student_arr.h"

void print_grades(Student_t students[], int num) {
	// For loop to print every student one line at a time
	for (int i =0; i < num; i++){
		printf("\nName: %-13s Grade: %.4lf %-3s Curved? %c",
				students[i].name, students[i].grade,
				students[i].letter, students[i].curved);
	}
	return;
}	
