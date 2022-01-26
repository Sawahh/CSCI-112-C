#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value;
    struct node* next;
} node_t;

node_t* create_new_node(int value) {
    node_t* result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return result;
}

void printlist(node_t *head) {
    node_t* cur = head;

    while (cur != NULL) {
        printf("%d -",  cur->value);
        cur = cur->next;
    }
    printf("\n");
}

int main(void) {
    node_t *head;
    node_t *tmp;

    tmp = create_new_node(32);
    head = tmp;
    tmp = create_new_node(8);
    tmp->next = head;
    head = tmp;
    tmp = create_new_node(45);
    tmp->next = head;
    head = tmp;

    printlist(head);

    return 0;
}

