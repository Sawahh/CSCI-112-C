#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value;
    struct node* next;
} node_t;

node_t* insert_at_head(node_t* head, node_t* node_to_insert) {
    node_to_insert->next = head;
    return node_to_insert;
}

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
    node_t *head = NULL;
    node_t *tmp;

    for (int i = 0; i < 25; i++) {
        tmp = create_new_node(i);
        head = insert_at_head(head, tmp);;
    }

    printlist(head);

    return 0;
}

