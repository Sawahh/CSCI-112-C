#include <stdio.h>
#include <string.h>
#include "grades.h"

void CalculateLetterGrade(Node_t** head) {

    // Created this to make the calculation code shorter and simpler
    // this struct is defined in grades.h
    Grade_t grades[11] = { {"A", 93.0}, {"A-", 90.0}, {"B+", 87.0},
                           {"B", 83.0}, {"B-", 80.0}, {"C+", 77.0},
                           {"C", 73.0}, {"C-", 70.0}, {"D+", 67.0},
                           {"D", 63.0}, {"D-", 60.0} };

    Node_t* current = *head;

    // While we still have nodes left...
    while(current != NULL){
	    // Loop through to compare and do calculations
	    for (int j = 0; j < 11; ++j){
		    if(current->student->grade >= (grades[j].lower_limit - 0.5)){
			    // Set teh letter grade string
			    strcpy(current->student->letter_grade, grades[j].letter);
			    // Find out if we had to curve it or not
			    if (current->student->grade < (grades[j].lower_limit)){
				    current->student->curved = 'y';
			    }
			    else {
				    current->student->curved = 'n';
			    }
			    break;
		    }
	    }
	    // Move on to the next node
	    current = current->next;
    }
    return;
}
             
