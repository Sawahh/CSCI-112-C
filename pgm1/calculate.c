#include "student_arr.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void calculate(Student_t students[], int num){
	// Set curved for all students to 'n'
	for (int i = 0; i < num; i++){
		students[i].curved = 'n';
	
	// Value for ease of function making
	double decimal = students[i].grade;

	// Lots of if statements to calculate the letter
	// and set the curved
	if(decimal >= 93.0){
		strcpy(students[i].letter, "A");
	}
	else if(decimal >= 90){
		if(decimal >= 92.5){
			strcpy(students[i].letter, "A");
			students[i].curved = 'y';
		}
		else{strcpy(students[i].letter, "A-");}
	}
	else if(decimal >= 87){
		if(decimal >= 89.5){
			strcpy(students[i].letter, "A-");
			students[i].curved = 'y';
		}
		else{strcpy(students[i].letter, "B+");}
	}
	else if (decimal >= 83){
		if (decimal >= 86.5){
			strcpy(students[i].letter, "B+");
			students[i].curved = 'y';
		}
		else{strcpy(students[i].letter, "B");}
	}
	else if (decimal >= 80){
		if (decimal >= 82.5){
			strcpy(students[i].letter, "B");
			students[i].curved = 'y';
		}
		else{strcpy(students[i].letter, "B-");}
	}
	else if (decimal >= 77){
		if (decimal >= 79.5){
			strcpy(students[i].letter, "B-");
			students[i].curved = 'y';
		}
		else{strcpy(students[i].letter, "C+");}
	}
	else if (decimal >= 73){
		if (decimal >= 76.5){
			strcpy(students[i].letter, "C+");
			students[i].curved = 'y';
		}
		else{strcpy(students[i].letter, "C");}
	}
	else if (decimal >= 70){
		if (decimal >= 72.5){
			strcpy(students[i].letter, "C");
			students[i].curved = 'y';
		}
		else{strcpy(students[i].letter, "C-");}
	}
	else if (decimal >= 67){
		if (decimal >= 69.5){
			strcpy(students[i].letter, "C-");
			students[i].curved = 'y';
		}
		else{strcpy(students[i].letter, "D+");}
	}
	else if (decimal >= 63){
		if (decimal >= 66.5){
			strcpy(students[i].letter, "D+");
			students[i].curved = 'y';
		}
		else{strcpy(students[i].letter, "D");}
	}
	else if (decimal >= 60){
		if (decimal >= 62.5){
			strcpy(students[i].letter, "D");
			students[i].curved = 'y';
		}
		else{strcpy(students[i].letter, "D-");}
	}
	}
}

