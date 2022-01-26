#include "grades.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SortedInsert(Node_t**, Node_t*);

void Sort(Node_t** head) {
	// Create a new Node_t* for the sorted linked list
	Node_t* sorted = NULL;

	Node_t* current = *head;
	// While we still have unsorted nodes in the saved linked list
	while (current != NULL){
		// Hold on to the next after current so we don't lose the whole list
		Node_t* next = current->next;

		// Use this to go into the SortedInsert function to keep this clean
		SortedInsert(&sorted, current);

		// Move on to the next node with what we have saved
		current = next;
	}
	// Change head to now point to the head of the sorted linked list
	*head = sorted;
	return;
}

void SortedInsert(Node_t** head, Node_t* new_node){

	Node_t* current;

	// If we need to make the new node the head
	if(*head == NULL ||
			(*head)->student->grade <= new_node->student->grade){
		new_node->next = *head;
		*head = new_node;
	}
	// Otherwise we search and find it's correct place
	else{
		current = *head;
		while (current->next != NULL && current->next->student->grade > new_node->student->grade){
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
	}
	return;
}
