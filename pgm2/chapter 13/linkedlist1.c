#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value;
    struct node* next;
} node_t;

void printlist(node_t *head) {
    node_t* cur = head;

    while (cur != NULL) {
        printf("%d -",  cur->value);
        cur = cur->next;
    }
    printf("\n");
}

int main(void) {
    node_t n1, n2, n3;
    node_t *head;

    n1.value = 45;
    n2.value = 8;
    n3.value = 32;

    // link them up
    head = &n3;
    n3.next = &n2;
    n2.next = &n1;
    n1.next = NULL;  // so we know where the list ends

    printlist(head);

    return 0;
}

