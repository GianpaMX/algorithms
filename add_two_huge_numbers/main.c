#include <list_node.h>
#include "add_two_huge_numbers.h"

int main() {
    list_node *a = list_node_new(1);

    list_node *b = list_node_new(9999);
    b->next = list_node_new(9999);
    b->next->next = list_node_new(9999);
    b->next->next->next = list_node_new(9999);
    b->next->next->next->next = list_node_new(9999);
    b->next->next->next->next->next = list_node_new(9999);


    list_node *c = add_two_huge_numbers(a, b);


    list_node_print(c);
    return 0;
}
