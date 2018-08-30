#include <stddef.h>
#include "merge_two_linked_lists.h"

/**
 * Iterating on both list at the same time until reach the end
 * of one.
 *
 * While iterating, compare elements and add the smallest to the result
 *
 * Finally just add the remaining elements of the other list
 *
 * @param a
 * @param b
 * @return
 */
list_node *merge_two_linked_lists(list_node *a, list_node *b) {
    list_node *result = NULL;

    list_node *p_a = a;
    list_node *p_b = b;
    list_node *p_r = result;

    int *val;
    while (p_a != NULL && p_b != NULL) {
        if (p_a->val < p_b->val) {
            val = &p_a->val;
            p_a = p_a->next;
        } else {
            val = &p_b->val;
            p_b = p_b->next;
        }

        if (result == NULL) {
            result = p_r = list_node_new(*val);
        } else {
            p_r = p_r->next = list_node_new(*val);
        }
    }

    // Only one of the following while-loops will be executed

    while (p_a != NULL) {
        if (result == NULL) {
            result = p_r = list_node_new(p_a->val);
        } else {
            p_r = p_r->next = list_node_new(p_a->val);
        }

        p_a = p_a->next;
    }

    while (p_b != NULL) {
        if (result == NULL) {
            result = p_r = list_node_new(p_b->val);
        } else {
            p_r = p_r->next = list_node_new(p_b->val);
        }

        p_b = p_b->next;
    }
    return result;
}
