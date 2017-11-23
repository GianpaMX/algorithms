#include <list_node.h>
#include "delete_duplicates.h"

int main() {
    list_node *list = list_node_new(1);
    list->next = list_node_new(1);
    list->next->next = list_node_new(2);
    list->next->next->next = list_node_new(3);
    list->next->next->next->next = list_node_new(3);

    list_node_print(list);

    list = delete_duplicates(list);

    list_node_print(list);

    return 0;
}
