#include <stdio.h>
#include "grades.h"

void PrintGrades(Node_t* head) {
    // Make an output file
    FILE* fout = fopen("out.txt", "w");
    
    Node_t* current = head;
    // While there are still nodes left to be printed
    while (current != NULL){
	    // Print with formatting
	    fprintf(fout, "Name: %s %s\tGrade: %-4lf %-3s Curved: %c\n",
			    current->student->first_name, current->student->last_name,
			    current->student->grade, current->student->letter_grade,
			    current->student->curved);
	    // Move on to the next node
	    current = current->next;
    }
    // Close the out.txt file
    fclose(fout);
    return;
}

