

#include "remove_k_from_list.h"

int main() {
    list_node *list = list_node_new(3);
    list->next = list_node_new(1);
    list->next->next = list_node_new(2);
    list->next->next->next = list_node_new(3);
    list->next->next->next->next = list_node_new(4);
    list->next->next->next->next->next = list_node_new(5);

    list = remove_k_from_list(list, 3);

    list_node_print(list);

    return 0;
}
