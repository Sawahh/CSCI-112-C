#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value;
    struct node* next;
} node_t;

node_t* insert_at_head(node_t** head, node_t* node_to_insert) {
    node_to_insert->next = *head;
    *head = node_to_insert;
    return node_to_insert;
}

node_t* find_node(node_t* head, int value) {
    node_t* cur = head;
    while (cur != NULL) {
        if (cur->value == value) {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

void insert_after_node(node_t* node_to_insert_after,
                          node_t* new_node) {
    new_node->next = node_to_insert_after->next;
    node_to_insert_after->next = new_node;
    return;
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
        insert_at_head(&head, tmp);;
    }

    tmp = find_node(head, 13);
    if (tmp != NULL) { // added this to make sure we don't
                       // get a segmentation fault if not
                       // found
        printf("found node with value %d\n", tmp->value);

        insert_after_node(tmp, create_new_node(75));
    }

    printlist(head);

    return 0;
}

