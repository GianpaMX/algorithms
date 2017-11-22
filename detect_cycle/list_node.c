#include <stdlib.h>
#include "list_node.h"

list_node *list_node_new(int val) {
    list_node *node = (list_node *) malloc(sizeof(list_node));
    node->val = val;
    node->next = NULL;
    return node;
}
