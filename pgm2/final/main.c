/* Sierra Stephens
 * April 24, 2020
 * CSCI 112
 * Program 2
 */

#include <stdio.h>
#include "grades.h"

// I am using the program 1 code that was given to us by 
// Mary Ann to start with 

int main(void) {

    // Make empty linked list	
    Node_t* list_head = NULL;

    // Read in the file and put the data into the linked list
    ReadGrades(&list_head);

    // Sort the linked list to be in order of highest to lowest grades
    Sort(&list_head);

    // Determine the letter grade and if it was curved or not
    CalculateLetterGrade(&list_head);

    // Print the result into out.txt
    PrintGrades(list_head);

    return(0);
}

