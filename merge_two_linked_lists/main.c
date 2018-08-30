
#include <list_node.h>
#include "merge_two_linked_lists.h"

int main() {
    list_node *list1 = list_node_new(1);
    list1->next = list_node_new(2);
    list1->next->next = list_node_new(3);

    list_node *list2 = list_node_new(4);
    list2->next = list_node_new(5);
    list2->next->next = list_node_new(6);

    list_node *result = merge_two_linked_lists(list1, list2);

    list_node_print(result);

    return 0;
}
