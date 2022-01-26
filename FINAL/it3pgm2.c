/* Sierra Stephens
 * 4/30/20
 * FINAL Pgm2
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int i;
}Integer_t;

typedef struct node_t{
	Integer_t* integer;
	struct node_t *next;
}Node_t;

// Function declarations
void Read(Node_t** head);
void InsertList(Node_t** head, Integer_t* integer);
void Print(Node_t* head);

int main(void){
	// Make empty linked list
	Node_t* list_head = NULL;

	// Read in txt file
	Read(&list_head);

	// Print to screen
	Print(list_head);

	return(0);
}

void Read(Node_t** head){
	// Open file copied in directory
	FILE* fin = fopen("numbers.txt", "r");
	
	// Check that file opened
	if (fin == NULL){
		printf("Cannot open file");
		return;
	}

	int num; 
	while (fscanf(fin, "%d", &num) > 0){
		// Make new memory
		Integer_t* integer = malloc(sizeof(Integer_t));
		integer->i = num;

		// Use seperate function to insert to the beginning of the list
		InsertList(head, integer);
	}
	return;
}

void InsertList(Node_t** head, Integer_t* integer){
	// Insert at the head of the list
	Node_t* new_node = malloc(sizeof(Node_t)); // Memory
	new_node->integer = integer; 

	Node_t* old_head = *head;
	*head = new_node;

	new_node->next = old_head; 

	return;
}

void Print(Node_t* head){
	// Print linked list to screen
	Node_t* current = head;

	while(current != NULL){
		printf("%d\n", current->integer->i);
		current = current->next; 
	}
	return;
}
