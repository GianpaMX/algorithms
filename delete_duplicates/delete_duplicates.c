#include <stddef.h>
#include "delete_duplicates.h"

list_node *delete_duplicates(list_node *list) {
    list_node *current = list;
    list_node *next = list->next;

    while (next != NULL) {
        if (next->val != current->val) {
            current = next;
        } else {
            current->next = next->next;
        }
        next = next->next;
    }

    return list;
}
