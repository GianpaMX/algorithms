#include <stddef.h>
#include "remove_k_from_list.h"

/**
 * Using two pointers two pointers to traverse the list one just behind
 * the other in a way that when first pointer finds an element with
 * value k updates the previous->next pointer to the k next node.
 *
 * Handling special case when we are the begining of the list where we
 * just simply move the start of the list forward.
 *
 * @param l
 * @param k
 * @return
 */
list_node *remove_k_from_list(list_node *l, int k) {
    list_node *node = l;
    list_node *previous_node = NULL;

    while (node != NULL) {
        if (node->val == k) {
            if (previous_node == NULL) {
                l = l->next;
            } else {
                previous_node->next = node->next;
            }
        } else {
            previous_node = node;
        };

        node = node->next;
    }

    return l;
}
