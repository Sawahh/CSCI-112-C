#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grades.h"

void ReadGrades(Node_t** head) {
    // Open the file I have copied into my directory
    FILE* fin = fopen("grades.txt", "r");
    // Char array for temporary storage
    char line[80];
  
    char *result;
    // Just in case something goes wrong opening the file 
    // I know where to look
    if (fin == NULL) {
        printf("ERROR: could not open input file\n");
    }
    // While we still have lines to gather info from...
    while (fgets(line, sizeof(line), fin) != NULL) {
	// Make some memory
	Student_t* student = malloc(sizeof(Student_t));
	// Breaking up the lines to gather the info
	result = strtok(line, ",");
        strcpy(student->last_name, result);
      
        result = strtok(NULL, ",");
        strcpy(student->first_name, result);        

        result = strtok(NULL, ",");
        sscanf(result, "%lf", &student->grade);
	// Making nodes
	Node_t* new_node = malloc(sizeof(Node_t));
	new_node->student = student;
	new_node->next = NULL;
	// Here is where the new nodes are put at the head
	// of the linked list
	Node_t* old_head = *head;// Make a temporary reference to not lose it
	*head = new_node;// The new node is now the head
	new_node->next = old_head;// The new head points to the old head
    }
    // Close the file
    fclose(fin);
    return;
} 
