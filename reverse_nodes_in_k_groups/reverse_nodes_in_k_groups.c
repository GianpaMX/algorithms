#include <stddef.h>
#include "reverse_nodes_in_k_groups.h"

list_node *reverse(list_node *start, list_node *end);

/**
 * Iterates over the list marking each k group with two pointers
 *
 * fist_k_node pointer is at the begining of current k group
 * last_k_node pinter is at the end of last k group
 *
 * When iterator is at k-factor element reverse the k group marked
 * by fist_k_node and the next element
 *
 * This should be O(n) because list is iterated two times
 *
 * @param list
 * @param k
 * @return
 */
list_node *reverse_nodes_in_k_groups(list_node *list, int k) {
    list_node *node = list;

    list_node *fist_k_node = list;
    list_node *last_k_node = NULL;

    list_node *first_k_list = NULL;

    int counter = 1;
    while (node != NULL) {
        list_node *next = node->next;
        if (counter % k == 0) {
            list_node *k_list = reverse(fist_k_node, next);
            if (last_k_node != NULL) {
                last_k_node->next = node;
            }
            last_k_node = fist_k_node;
            if (first_k_list == NULL) first_k_list = k_list;
            fist_k_node = next;
        }
        node = next;
        counter++;
    }

    return first_k_list;
}

list_node *reverse(list_node *start, list_node *end) {
    list_node *node = start;
    list_node *previous = end;
    do {
        list_node *next = node->next;
        node->next = previous;
        previous = node;
        node = next;
    } while (node != end);
    return previous;
}
