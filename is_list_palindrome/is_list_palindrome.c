
#include <stddef.h>
#include "is_list_palindrome.h"

/**
 *
 * @param l
 * @return
 */
bool is_list_palindrome(list_node *l) {
    list_node *n = l;
    list_node *f = l;
    list_node *r = NULL;

    while (n != NULL) {
        list_node *next = n->next;
        if (f != NULL) {
            f = f->next;
            if (f != NULL) {
                f = f->next;

                n->next = r;
                r = n;
            }
        } else if (r != NULL && r->val == n->val) {
            r = r->next;
        } else {
            return false;
        }
        n = next;
    }

    return true;
}
