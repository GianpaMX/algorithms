#include <stdio.h>

#include "list_node.h"
#include "detect_cycle.h"

int main() {
    list_node *list = list_node_new(1);
    list_node *two = list->next = list_node_new(2);
    list_node *three = list->next->next = list_node_new(3);
    three->next = list_node_new(4);
    three->next->next = list_node_new(5);
    list_node *six = three->next->next->next = list_node_new(6);
    six->next = three;

    list_node *node = detect_cycle(list);

    printf("%d\n", node->val);

    return 0;
}
