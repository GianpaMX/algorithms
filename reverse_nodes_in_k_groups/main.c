#include <list_node.h>
#include "reverse_nodes_in_k_groups.h"

int main() {
    list_node *list1 = list_node_new(1);
    list1->next = list_node_new(2);
    list1->next->next = list_node_new(3);
    list1->next->next->next = list_node_new(4);
    list1->next->next->next->next = list_node_new(5);

    reverse_nodes_in_k_groups(list1, 3);

    list_node_print(list1);

    return 0;
}
