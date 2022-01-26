/* Sierra Stephens
 * CSCI 112
 * April 9, 2020
 * Program 1
 */

#include <stdio.h>
#include "student_arr.h"

int main() {
	Student_t students[50]; // Initialize struct array
	int no_students = read_grades(students); // Number of students
	calculate(students, no_students); // Calculate letter grade and curve
	print_grades(students, no_students); // Printing using no_students
	printf("\n"); // Formatting

	return(0);
}

