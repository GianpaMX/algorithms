#include <stddef.h>
#include <stack.h>
#include "add_two_huge_numbers.h"

/**
 * Put all numbers from each parameter into two stacks in order to reverse them
 *
 * Then pop them at the same time to sum each other and calculate the accumulator
 * until any stack is empty
 *
 * Then just keep adding sumbers to the result of the remaining stack considering
 *
 * At the end if the accumulator is greater than zero, add it to the result
 *
 * @param a
 * @param b
 * @return
 */
list_node *add_two_huge_numbers(list_node *a, list_node *b) {
    list_node *result = NULL;
    list_node *p = a;

    stack *s_a = stack_init(sizeof(int));
    while (p != NULL) {
        s_a->push(s_a, &p->val);
        p = p->next;
    }

    p = b;

    stack *s_b = stack_init(sizeof(int));
    while (p != NULL) {
        s_b->push(s_b, &p->val);
        p = p->next;
    }

    int sum_a, sum_b, sum, acc = 0;
    while (s_a->size(s_a) > 0 && s_b->size(s_b) > 0) {
        s_a->pop(s_a, &sum_a);
        s_b->pop(s_b, &sum_b);

        sum = sum_a + sum_b + acc;

        if (sum >= 10000) {
            acc = 1;
            sum = sum - 10000;
        } else {
            acc = 0;
        }

        list_node *node_sum = list_node_new(sum);
        node_sum->next = result;
        result = node_sum;
    }

    // Only one of the following while-loops will be executed

    while (s_a->size(s_a) > 0) {
        s_a->pop(s_a, &sum_a);
        sum = sum_a + acc;

        if (sum >= 10000) {
            acc = 1;
            sum = sum - 10000;
        } else {
            acc = 0;
        }

        list_node *node_sum = list_node_new(sum);
        node_sum->next = result;
        result = node_sum;
    }

    while (s_b->size(s_b) > 0) {
        s_b->pop(s_b, &sum_b);
        sum = sum_b + acc;

        if (sum >= 10000) {
            acc = 1;
            sum = sum - 10000;
        } else {
            acc = 0;
        }

        list_node *node_sum = list_node_new(sum);
        node_sum->next = result;
        result = node_sum;
    }

    if (acc > 0) {
        list_node *node_sum = list_node_new(acc);
        node_sum->next = result;
        result = node_sum;
    }

    return result;
}
