#include <stdlib.h>
#include <stdio.h>
#include "list_node.h"

list_node *list_node_new(int val) {
    list_node *node = (list_node *) malloc(sizeof(list_node));
    node->val = val;
    node->next = NULL;
    return node;
}

void list_node_print(list_node *list) {
    list_node *node = list;

    while (node != NULL) {
        printf("%d", node->val);

        if (node->next != NULL) {
            printf(" -> ");
        }
        node = node->next;
    }

    printf("\n");
}
