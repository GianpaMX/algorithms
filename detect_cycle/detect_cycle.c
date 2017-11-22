#include <stddef.h>

#include "detect_cycle.h"

/**
 * We have to pointers, slow moves one step at a time, fast moves two steps at a time.
 * If there is a loop those two pointers will meet
 *
 * @param head
 * @return
 */
list_node *find_meeting_point(list_node *head) {
    list_node *slow = head;
    list_node *fast = head;
    list_node *meeting_point = NULL;

    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            meeting_point = slow;
            break;
        }
    }
    return meeting_point;
}

/**
 * This works because the distance from the meeting point to the start of the loop is equals to
 * the distance from the head of the list to the start of the loop.
 *
 * That is true because the distance traveled by the fast pointer is exactly the double of the
 * slow pointer so the distance from the head of the list to the meeting point is in terms of the length
 * of the cycle
 *
 * @param p Head pointer of linked list
 * @return node where the cycle starts or null
 */
list_node *detect_cycle(list_node *list) {
    list_node *q = find_meeting_point(list);

    if (!q) return NULL;

    list_node *p = list;

    while (p != q) {
        p = p->next;
        q = q->next;
    }
    return p;
}
