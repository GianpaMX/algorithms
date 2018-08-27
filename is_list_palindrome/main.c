

#include <stdio.h>
#include "is_list_palindrome.h"

int main() {
    list_node *list = list_node_new(1);
//    list->next = list_node_new(2);
//    list->next->next = list_node_new(3);
//    list->next->next->next = list_node_new(3);
//    list->next->next->next->next = list_node_new(2);
//    list->next->next->next->next->next = list_node_new(1);

    list->next = list_node_new(2);
    list->next->next = list_node_new(3);
    list->next->next->next = list_node_new(4);
    list->next->next->next->next = list_node_new(3);
    list->next->next->next->next->next = list_node_new(2);
    list->next->next->next->next->next->next = list_node_new(1);


    list_node_print(list);

    bool r = is_list_palindrome(list);

    printf("%s\n", r ? "true" : "false");

    return 0;
}
