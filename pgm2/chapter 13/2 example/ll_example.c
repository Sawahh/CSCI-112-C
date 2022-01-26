#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// a simple struct to hold a number
typedef struct {
    int num1;
} Data_t;

// struct for a node in a linked list
typedef struct node_t {
    Data_t* d;
    struct node_t *next;
} Node_t;

// declarations of functions needed
void Read(Node_t**);
void Sort(Node_t**);
void Print(Node_t*);
void ListInsert(Node_t**, Data_t*);
void SortedInsert(Node_t**, Node_t*);

int main(void) {

    // an empty linked list
    Node_t* list_head = NULL;

    // read in the file and put the data into a linked list
    Read(&list_head);

    // sort list by num1 from lowest to highest 
    Sort(&list_head);

    // print out list 
    Print(list_head);

    return(0);
}

void Read(Node_t** head) {

    FILE* infptr = fopen("in.txt", "r");

    if (infptr == NULL) {
        printf("ERROR: could not open input file\n");
        exit(1);
    }

    int num_read;
    while (fscanf(infptr, "%d", &num_read) > 0) {
        // have to do this here to get a new address each time
        Data_t* d = malloc(sizeof(Data_t));
        d->num1 = num_read;
   
        ListInsert(head, d);
    }
    return;
} 

void ListInsert(Node_t** head, Data_t* d) {

    // insert at the head
    Node_t* new_node = malloc(sizeof(Node_t));
    new_node->d = d;

    Node_t* old_head = *head;
    *head = new_node;

    new_node->next = old_head;

    return;
} 

void Print(Node_t* head) {
    
    FILE* outfptr = fopen("out.txt", "w");

    Node_t* cur = head;

    while (cur != NULL) {
        fprintf(outfptr, "%d\n", cur->d->num1);
        cur = cur->next;
    }
    return;
}

// sorts the nodes in the list by creating a new list and adding 
// the right node to the list at the right time
void Sort(Node_t** head) {
    // this is our new list, starts out empty
    Node_t* sorted = NULL;

    // this is a pointer to the first node in our unsorted list 
    Node_t* cur = *head;
    while (cur != NULL) {

        // we have to hold on to the next node because
        // the call to sorted insert may change our cur pointer
        Node_t* next = cur->next;

        // insert our current node into the sorted list in 
        // the right place
        SortedInsert(&sorted, cur);

        cur = next;
    }

    // head now points to the head of the sorted list
    *head = sorted;
    return;
}

// move each node to the sorted linked list into the
// right sorted position in that list
void SortedInsert(Node_t** head, Node_t* new_node) {

    Node_t* cur;

    // special case for making new node the head
    if (*head == NULL || 
        (*head)->d->num1 >= new_node->d->num1) {

        new_node->next = *head;
        *head = new_node;
    }
    else {
        cur = *head;
        // find the right node to insert the new node in front of
        while (cur->next != NULL &&
              cur->next->d->num1 < new_node->d->num1) { 

            cur = cur->next;
        }
        new_node->next = cur->next;
        cur->next = new_node;
    }
    return;
}
