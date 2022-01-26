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
    node_t *head = NULL;
    node_t *tmp;

    for (int i = 0; i < 25; i++) {
        tmp = create_new_node(i);
        tmp->next = head;
        head = tmp;
    }

    printlist(head);

    return 0;
}

